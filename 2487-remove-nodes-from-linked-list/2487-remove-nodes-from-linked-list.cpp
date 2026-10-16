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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int maxi = INT_MIN;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            if (curr->val < maxi) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                maxi = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }

        return reverse(head);
    }
};