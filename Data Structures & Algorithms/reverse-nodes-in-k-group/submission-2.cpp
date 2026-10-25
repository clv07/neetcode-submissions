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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // find the k-th node from groupPrev
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) kth = kth->next;
            if (!kth) break; // fewer than k left

            ListNode* groupStart = groupPrev->next;  // first in group
            ListNode* groupNext  = kth->next;        // first after group
            
            // reverse k nodes, the tail links to groupNext
            ListNode* prev = groupNext;
            ListNode* curr = groupStart;
            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            groupPrev->next = kth;   // before → new first
            groupPrev = groupStart;  // old first is now the new "before"
        }

        return dummy.next;
    }
};
