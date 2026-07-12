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
        Node* ptr = head;
        // Inserting new Nodes
        while(ptr){
            Node* node = new Node(ptr->val);
            node->next = ptr->next;
            ptr->next = node;
            ptr = node->next;
        }
        // Updating random pointers
        ptr = head;
        while(ptr){
            if(ptr->random)
            ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }

        // Seperating nodes
        Node* newHead = head?head->next:nullptr;
        ptr = head;
        while(ptr){
            Node* copy = ptr->next;
            ptr->next = copy->next;
            if(copy->next)
            copy->next = copy->next->next;
            ptr = ptr->next;
        }
        return newHead;

    }
};