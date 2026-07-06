class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        unordered_map<Node*, Node*> cloned;   // original -> its clone
        stack<Node*> toProcess;

        toProcess.push(node);
        cloned[node] = new Node(node->val);    // clone up front, empty neighbors

        while (!toProcess.empty()) {
            Node* cur = toProcess.top(); toProcess.pop();

            for (Node* nb : cur->neighbors) {
                if (!cloned.contains(nb)) {        // first time seeing this neighbor
                    cloned[nb] = new Node(nb->val);
                    toProcess.push(nb);
                }
                cloned[cur]->neighbors.push_back(cloned[nb]);  // wire clone->clone
            }
        }

        return cloned[node];
    }
};