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
    int pairSum(ListNode* head) {
       int len =0;
       ListNode* ptr = head;
       while(ptr){
        len++;
        ptr = ptr->next;
       }
       ptr=head;
    //    if(len == 2){
    //     return (ptr->val+ptr->next->val);
    //    }
       len = len/2;
       ListNode* prevMid = nullptr;
       while(len--){
        prevMid = ptr;
        ptr = ptr->next;
       } 
    //    ListNode* node = ptr->next;
    //    cout<<node->val<<" "<<ptr->val;
       prevMid->next = nullptr;
       ListNode* prev = nullptr,*ptr2 = ptr,*nxt = nullptr;
       while(ptr2){
        nxt = ptr2->next;
        ptr2->next = prev;
        prev = ptr2;
        ptr2 = nxt;
       }
        ptr2 = prev;
        ptr = head;
        int res = 0;
        while(ptr2 and ptr){
            res = max(res, ptr->val+ptr2->val);
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        return res;
    }
};