/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
bool check(ListNode *headA, ListNode *headB){
    ListNode* ptr1 = headA;
    ListNode* ptr2 = headB;
    while(ptr1 and ptr2){
        if(ptr1 != ptr2){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}
int intersectionVal=0,skipA=0,skipB=0;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //    ListNode* ptr1 = headA;
    //    ListNode* ptr2 = headB;
    //    int l1=0,l2=0;
    //    while(ptr1->next !=nullptr){
    //     l1++;
    //     ptr1 = ptr1->next;
    //    }
    //    while(ptr2->next !=nullptr){
    //     l2++;
    //     ptr2 = ptr2->next;
    //    }
    //    if(ptr1 != ptr2){
    //     return nullptr;
    //    }
    //    while(l1 > l2){
    //      headA = headA->next;
    //      l1--;
    //    }
    //    while(l2>l1){
    //     headB = headB->next;
    //     l2--;
    //    }
    //    while(headA != nullptr and headB != nullptr ){
    //     if((headA == headB) and (headA->val == headB->val)){
    //         if(check(headA,headB)){
    //             return headA;
    //         }
    //     }
    //     headA = headA->next;
    //     headB = headB->next;
    //    }
    //    return nullptr;
    
    // #Approach 2
    // ListNode* ptr1= headA;
    // ListNode* ptr2= headB;
    // while(ptr1 != ptr2){
    //     // if(ptr1== ptr2){
    //     //     return ptr1;
    //     // }
    //     if(!ptr1){
    //         ptr1 = headA;
    //     }
    //     else{
    //         ptr1= ptr1->next; 
    //     }
    //     if(!ptr2){
    //         ptr2 = headB;
    //     }
    //     else{
    //         ptr2= ptr2->next; 
    //     }
    // }
    // return ptr1;

    ListNode* ptr1 = headA,*ptr2 = headB;
    int len1 = 0 ,len2 = 0;
    while(ptr1){
        ptr1= ptr1->next;
        len1++;
    }
    while(ptr2){
        ptr2= ptr2->next;
        len2++;
    }
    ptr1 = headA;
    ptr2 = headB;
    while(len1>len2){
        ptr1 = ptr1->next;
        
        len1--;
    }
    while(len2>len1){
        ptr2 = ptr2->next;
        len2--;
    }
    if((!ptr1 and ptr2) or (ptr1 and !ptr2)) return nullptr;
    while( ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
    }
};