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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return nullptr; 
        ListNode* root = nullptr,*ptr2 = nullptr,*ptr = head;
        // bool done = false;
        ListNode* start = head->next, *end = head->next;
        while(end){
            
                int sum = 0;
                while(end->val !=0){
                    sum += end->val;
                    end = end->next;
                }
                start->val = sum;
                end = end->next;
                if(!end){
                    start->next = nullptr;
                    break;
                }
                start->next = end;
                start = end;
            
        }   
        return head->next;
    }
};