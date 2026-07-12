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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* value1,*value2,*ptr = head;
        // Getting first value by  traversing till the kth node in the linked list from the beginning
        for(int i=1;i<k ; i++){
            if(ptr){
                ptr=ptr->next;
            }
            else{
                return head;
            }
        }
        value1 = ptr;
        // cout<<value1->val<<endl;
        // For getting kth node from the end
        int count = k;
        while(ptr){
            ptr = ptr->next;
            count++;
        }
        int j = count-k;
        if(count == j){
            return head;
        } 
        // cout<<"j "<<j<<endl;
        ptr = head;
        while(j>1){
            ptr = ptr->next;
            j--;
        }
        value2 = ptr;

        // Swapping
        swap(value1->val,value2->val);
        return head;
    }
};