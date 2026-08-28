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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        int length = 1;
        ListNode* curr = head;
        while (curr->next != nullptr) { length++; curr = curr->next; }

        int steps = length / 2;          // fixed count, computed once
        ListNode* prev = nullptr;
        curr = head;
        while (steps-- > 0) { prev = curr; curr = curr->next; }
        prev->next = nullptr;            // cut: first half now terminated

        ListNode* second = reverseList(curr);

        ListNode dummy(0);
        ListNode* tail = &dummy;         // cursor, dummy never moves
        curr = head;
        while (curr != nullptr && second != nullptr) {
            tail->next = curr;  tail = tail->next;  curr = curr->next;
            tail->next = second; tail = tail->next; second = second->next;
        }
        tail->next = (curr != nullptr) ? curr : second;   // at most one node left
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head ->next == nullptr)
            return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};
