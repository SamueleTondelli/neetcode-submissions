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
        if (!head) return head;

        ListNode *curr = head, *prev = nullptr, *next = head->next;
        while (next) {
            curr->next = prev;
            ListNode* following = next->next;
            next->next = curr;

            prev = curr;
            curr = next;
            next = following;
        }
        return curr;
    }
};
