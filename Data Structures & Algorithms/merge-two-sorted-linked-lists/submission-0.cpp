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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;                 // defensive: empty input
        if (!list2) return list1;

        if (list2->val < list1->val) std::swap(list1, list2);  // list1 = smaller head
        ListNode* head = list1;

        // list1 = tail of merged result so far; list2 = head of the "other" list
        while (list1->next != nullptr && list2 != nullptr) {
            if (list1->next->val <= list2->val) {
                list1 = list1->next;              // own next is smaller: just advance
            } else {
                ListNode* tmp = list1->next;      // save displaced chain
                list1->next = list2;              // splice other list in
                list2 = tmp;                      // other becomes the remaining chain
                list1 = list1->next;              // step onto the spliced node
            }
        }
        if (list2) list1->next = list2;           // attach whatever's left
        return head;

    }
};
