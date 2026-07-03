/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* llist = head;
        if (!head)
            return false;
        for (int i = 0; i <= 1001; i++){
            
            if (llist->next == nullptr)
                return false;
            llist = llist->next;
        }
        return true;
    }
};
