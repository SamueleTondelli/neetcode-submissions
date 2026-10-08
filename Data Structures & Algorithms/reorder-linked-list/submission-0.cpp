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
        vector<ListNode*> v;
        ListNode* curr = head;
        while (curr) {
            v.push_back(curr);
            curr = curr->next;
        }

        int i = 0, j = v.size() - 1;
        while (i < j) {
            v[j]->next = v[i]->next;
            v[i]->next = v[j];
            i++;
            j--;
        }
        v[i]->next = nullptr;
    }
};
