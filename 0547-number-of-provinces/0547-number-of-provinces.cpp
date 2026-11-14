class Solution {
public:
int find(vector<int>& parent, int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent,parent[i]);
    }
    void Union(int u,int v, vector<int>&parent){
        int pu = find(parent,u);
        int pv = find(parent,v);
        if(pu != pv){
            parent[pu] = pv;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         vector<int>parent(isConnected.size());
        for(int i = 0 ; i<isConnected.size() ; i++){
            parent[i] = i;
        }
        int count = isConnected.size();
        for(int i = 0 ; i<isConnected.size(); i++){
            for(int j = i+1; j<isConnected.size(); j++){
                if(isConnected[i][j] == 1){
                    int pi = find(parent,i);
                    int pj = find(parent,j);
                    if(pi != pj){
                        Union(i,j,parent);
                        count--;
                    }
                }
            }
        }
        return count;
    }
};