class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // how long is the list?
        ListNode* curr = head;
        int list_length = 0;
        while (curr != nullptr){
            curr = curr->next;
            list_length++;
        }

        // move n/2 forward, tracking the node before curr
        int n = list_length / 2;
        curr = head;
        ListNode* new_tail = nullptr;     // CHANGED: trails one behind curr
        while (n > 0){
            new_tail = curr;              // CHANGED: remember node before midpoint
            curr = curr->next;
            n--;
        }
        new_tail->next = nullptr;         // CHANGED: sever first half; curr = start of 2nd half

        // reverse second half
        ListNode* prev = nullptr;
        ListNode* next;
        while (curr->next != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        ListNode* new_head = curr;

        // merge the two halves
        ListNode dummy(0);
        ListNode* res = &dummy;
        ListNode *l1 = head, *l2 = new_head;
        while (l1 != nullptr || l2 != nullptr){   // CHANGED: test pointers, not ->next
            if (l1) {
                res->next = l1;
                l1 = l1->next;
                res = res->next;
            }
            if (l2) {
                res->next = l2;
                l2 = l2->next;
                res = res->next;
            }
        }
    }
};