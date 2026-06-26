
// Definition for singly-linked list.
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* curr;
        vector<ListNode*> nodes;
        curr = head;
        while(curr->next != nullptr){
            nodes.push_back(curr);
            curr = curr->next;
        }
        nodes.push_back(curr);
        for (int i = (int)nodes.size() - 1; i>0; i--){
            curr->next = nodes[i-1];
            curr = nodes[i-1];
        }
        curr->next = nullptr;
        return nodes.back();
    }    
};
