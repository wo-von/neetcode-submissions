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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // custom comparator for the heap
        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (const auto &l: lists){ // only push non null
            if (l) q.push(l);
        }
        struct ListNode dummy;
        struct ListNode *tail = &dummy;
        while(!q.empty()){
            auto lowest = q.top(); q.pop(); // node with lowest number
            tail->next = lowest; // point tail to it and move tail to it
            tail = tail->next;
            lowest = lowest->next; // advance it and push it only if non null
            if (lowest) q.push(lowest);
        }
        return dummy.next;
    }
};
