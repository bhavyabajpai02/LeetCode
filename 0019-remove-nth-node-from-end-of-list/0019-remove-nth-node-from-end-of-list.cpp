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
        int count = 0;
        ListNode* ptr = head;
        while(ptr != nullptr){
            count++;
            ptr = ptr->next;
        }
        if(count==n){
            ListNode* d = head;
            head = head->next;
            delete d;
            return head;
        }
        ptr = head;
        int i = count-n-1;
        while(i--){
            ptr = ptr->next;
        }
        ListNode* d = ptr->next;
        ptr->next = ptr->next->next;
        delete d;
        return head;

    }
};