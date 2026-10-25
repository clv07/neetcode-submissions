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
        // 1. determine how many rounds of reversal through counting total number of nodes
        int total = 0;
        for (ListNode* node = head; node; node=node->next) total++;
        int round = total / k;

        ListNode dummy(0, head); 
        ListNode* groupPrev = &dummy; // tail of the last finished group
        ListNode* curr = head;

        while(round-- > 0) {
            ListNode* groupStart = curr; // becomes this group's tail
            ListNode* prev = nullptr;

            // reverse of k nodes
            for (int i = 0; i < k; i++) { 
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // now: prev = new group head, curr = next group's first node
            groupPrev->next = prev;     // connect previous group to new group head
            groupStart->next = curr;    // connect this group's tail to next group's first node
            groupPrev = groupStart;     // move on

        }

        return dummy.next;

    }
};
