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

    ListNode* insertNode(ListNode* head, ListNode* node) {

        // Insert at beginning
        if (head == nullptr || node->val <= head->val) {
            node->next = head;
            return node;
        }

        ListNode* curr = head;

        while (curr->next && curr->next->val < node->val) {
            curr = curr->next;
        }

        node->next = curr->next;
        curr->next = node;

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* result = nullptr;

        for (ListNode* head : lists) {

            while (head) {

                ListNode* nextNode = head->next;
                head->next = nullptr;

                result = insertNode(result, head);

                head = nextNode;
            }
        }

        return result;
    }
};