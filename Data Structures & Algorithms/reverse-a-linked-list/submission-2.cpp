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
    ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;                       // base case

    ListNode* newHead = reverseList(head->next);  // reverse the rest first
    head->next->next = head;               // make the node after me point back at me
    head->next = nullptr;                  // I'm the new tail
    return newHead;                        // new head bubbles up unchanged
    }
};
