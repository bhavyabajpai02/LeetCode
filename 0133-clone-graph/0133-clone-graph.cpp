/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> graph;
        unordered_set<int>st;
        // dfs(graph,node,st);
        queue<Node*>q;
        q.push(node);
        graph[node] = new Node(node->val);
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
                for(Node* i:n->neighbors){
                    if(!graph.count(i)){
                        graph[i] = new Node(i->val);
                        q.push(i);
                    }
                    graph[n]->neighbors.push_back(graph[i]);
                }
            
        }
        return graph[node];
    }
};