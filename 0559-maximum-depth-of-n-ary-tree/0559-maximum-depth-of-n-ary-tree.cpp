/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*> q;
        q.push(root);
        int height = 1;
        while(!q.empty()){
        bool check = false;
        int n = q.size();
        for(int i=0 ; i<n ; i++){
            Node* node = q.front();
            q.pop();
            if(node->children.empty()) continue;
            for(Node* p:node->children){
                if(!check) check=true;
                q.push(p);
            }
        }
        if(check) height++;
        }
        return height;
    }
};