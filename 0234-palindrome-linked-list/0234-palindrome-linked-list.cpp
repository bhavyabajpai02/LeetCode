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
    ListNode* getMid(ListNode* head){
        ListNode* slow= head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    } 
    ListNode* reverse(ListNode* next){
        if(!next) return nullptr ;
        ListNode* ptr = next,*nxt =nullptr,*prev = nullptr;
        while(ptr){
            nxt = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head and !head->next) return true;
        ListNode* mid = getMid(head);
        ListNode* next = mid->next;
        ListNode* reversed = reverse(next),*ptr = head;
        ListNode*ptr2 = reversed;
        while(ptr and ptr2){
            if(ptr->val != ptr2->val){
                return false;
            }
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        // mid->next = 
        return true;
    }
};