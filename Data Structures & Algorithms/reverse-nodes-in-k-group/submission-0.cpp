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
        // reverse
        // which node to remember/track of

        // 1. determine if remaining list has k nodes
        // traverse the list one time to count how many nodes in total
        // round = total // k 
        // firstRound = round

        // 2. reverse k nodes
        // while (!round && curr)
        // prevGroup = nullptr
        // prev, curr, count
        // record temp = curr's next
        // if count == 1, point curr's next to prevGroup, then record prevGroup = curr, if round == firstRound, record it as head of the ListNode
        // else point curr's next to prev
        // advance curr = temp and prev = curr
        // round--;

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
