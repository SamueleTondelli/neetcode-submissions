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
    bool hasCycle(ListNode* head) {
        if (!head || !head->next || !head->next->next) return false;
        ListNode* slow = head, *fast = head->next->next;
        while (slow && fast) {
            if (slow == fast) {
                return true;
            }

            slow = slow->next;
            if (!fast->next) {
                break;
            }
            fast = fast->next->next;
        }
        return false;
    }
};
