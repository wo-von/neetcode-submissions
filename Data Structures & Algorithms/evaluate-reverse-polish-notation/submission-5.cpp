class Solution {
public:

struct Node {
    string val;
    Node* left;
    Node* right;
    Node(string v) : val(v), left(nullptr), right(nullptr) {}
};

bool isOp(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

Node* buildTree(vector<string>& tokens) {        // pass 1: stack of subtrees
    stack<Node*> st;
    for (const string& tok : tokens) {
        Node* node = new Node(tok);
        if (isOp(tok)) {
            node->right = st.top(); st.pop();    // right child popped first
            node->left  = st.top(); st.pop();    // then left
        }
        st.push(node);
    }
    return st.top();                             // the root
}

int evalTree(Node* root) {                       // pass 2: post-order DFS
    stack<Node*> order, s;
    s.push(root);
    while (!s.empty()) {                         // build reverse post-order
        Node* n = s.top(); s.pop();
        order.push(n);
        if (n->left)  s.push(n->left);
        if (n->right) s.push(n->right);
    }
    stack<int> vals;
    while (!order.empty()) {                     // pop = post-order
        Node* n = order.top(); order.pop();
        if (isOp(n->val)) {
            int b = vals.top(); vals.pop();      // right operand
            int a = vals.top(); vals.pop();      // left operand
            if      (n->val == "+") vals.push(a + b);
            else if (n->val == "-") vals.push(a - b);
            else if (n->val == "*") vals.push(a * b);
            else                    vals.push(a / b);
        } else {
            vals.push(stoi(n->val));
        }
    }
    return vals.top();
}

int evalRPN(vector<string>& tokens) {
    return evalTree(buildTree(tokens));
}
};
