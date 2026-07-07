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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;
        while(curr) {
            len += 1;
            curr = curr->next;
        }

        int target = len - n;

        if (target == 0) return head->next;

        curr = head;
        for(int i = 0; i < target; i++) {
            if ((i+1) == target) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
