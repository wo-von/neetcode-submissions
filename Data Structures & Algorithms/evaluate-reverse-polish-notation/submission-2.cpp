struct DoublyLinkedList {
    string val;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;
    DoublyLinkedList(string val, DoublyLinkedList* next=nullptr,
                     DoublyLinkedList* prev=nullptr)
        : val(val), next(next), prev(prev) {}
};

class Solution {
    string ops = "+-*/";
public:
    int evalRPN(vector<string>& tokens) {
        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;
        for (size_t i = 1; i < tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i], nullptr, curr);
            curr = curr->next;
        }
        int result = 0;
        curr = head;
        while (curr != nullptr) {
            if (ops.find(curr->val) != string::npos) {
                int op1 = stoi(curr->prev->prev->val);
                int op2 = stoi(curr->prev->val);
                switch (curr->val[0]) {
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': result = op1 / op2; break;
                }
                curr->val = to_string(result);
                curr->prev = curr->prev->prev->prev;
                if (curr->prev != nullptr) {
                    curr->prev->next = curr;
                }
            }
            result = stoi(curr->val);
            curr = curr->next;
        }
        return result;
    }
};