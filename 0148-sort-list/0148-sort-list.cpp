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
    private:
    ListNode* findMid(ListNode* head){
        if(!head or !head->next) return head;
        ListNode* slow = head,*fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right){
        if(!left) return right;
        if(!right) return left;
        ListNode* newll = new ListNode(0),*l = left,*r = right,*curr = newll;
        while(l and r){
            if(l->val <= r->val){
                curr->next = new ListNode(l->val);
                l = l->next;
            }
            else{
                curr->next = new ListNode(r->val);
                r = r->next;
            }
            curr = curr->next;
        }
        while(l){
            curr->next = new ListNode(l->val);
            l = l->next;
            curr = curr->next;
        }
        while(r){
            curr->next = new ListNode(r->val);
            r = r->next;
            curr = curr->next;
        }
        return newll->next;
    }
public:

    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        // priority_queue<int,vector<int>,greater<int>>pq;
        // ListNode* ptr = head;
        // while(ptr){
        //     pq.push(ptr->val);
        //     ptr = ptr->next;
        // }
        // ptr = head;
        // while(!pq.empty()){
        //     ptr->val = pq.top();
        //     ptr = ptr->next;
        //     pq.pop();
        // }
        // ListNode* ptr = head;
        if(!head or !head->next) return head;
        ListNode* mid = findMid(head);
        // cout<<mid->val<<endl;
        ListNode* left = head,*right = mid->next;
        mid->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        // return head;
        return merge(left,right);
    }
};