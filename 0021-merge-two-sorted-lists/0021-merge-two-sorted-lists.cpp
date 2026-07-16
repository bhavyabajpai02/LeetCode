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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode*ptr1 = list1,*ptr2 = list2, *next1 = list1->next, *next2 = list2->next;
        while(next1 and ptr2){
            next2 = ptr2->next;
            if(ptr1->val <= ptr2->val and ptr2->val < next1->val){
                ptr2->next = ptr1->next;
                ptr1->next = ptr2;
                ptr1 = ptr2; 
                ptr2 = next2;
            }
            else{
                ptr1 = next1;
                next1= next1->next;
                if(!next1){
                    ptr1->next = ptr2;
                    return list1;
                }
            }
        }
        
        
        return list1;

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val<= list2->val){
            if(list1->next == nullptr) {
                list1->next = list2;
                return list1;
            }
           return  merge(list1,list2);
        } 
        if(list2->next == nullptr){
            list2->next = list1;
            return list2;
        }
            return merge(list2,list1);
        
    }
};