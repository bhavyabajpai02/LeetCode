/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Node* ptr = head;
        // // Inserting new Nodes
        // while(ptr){
        //     Node* node = new Node(ptr->val);
        //     node->next = ptr->next;
        //     ptr->next = node;
        //     ptr = node->next;
        // }
        // // Updating random pointers
        // ptr = head;
        // while(ptr){
        //     if(ptr->random)
        //     ptr->next->random = ptr->random->next;
        //     ptr = ptr->next->next;
        // }

        // // Seperating nodes
        // Node* newHead = head?head->next:nullptr;
        // ptr = head;
        // while(ptr){
        //     Node* copy = ptr->next;
        //     ptr->next = copy->next;
        //     if(copy->next)
        //     copy->next = copy->next->next;
        //     ptr = ptr->next;
        // }
        // return newHead;

        // new List
        Node* newHead = nullptr,*curr = nullptr,*ptr = head;
        while(ptr){
            if(!newHead){
                newHead = new Node(ptr->val);
                curr = newHead;
            }
            else{
                curr->next = new Node(ptr->val);
                curr = curr->next;
            }
            ptr = ptr->next;
        }

        // combining new + orginal list 
        curr = newHead;
        ptr = head;
        Node* nextcopy = nullptr,*nextorg = nullptr;
        while(ptr){
            nextorg = ptr->next;
            ptr->next = curr;
            ptr = nextorg;
            nextcopy = curr->next;
            curr->next = ptr;
            curr = nextcopy;
        }

        // setting random pointers
        ptr = head;
        while(ptr){
            if(ptr->random){
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }

        // splitting new and org
        ptr = head;
        curr = newHead;
        while(ptr){
            ptr->next = curr->next;
            ptr = ptr->next;
            if(ptr){
                curr->next = ptr->next;
            }
                curr = curr->next;
        }
        return newHead;
    }
};