class Solution {
public:
    void solve(vector<vector<int>>&adj, vector<int>&visit, int i, bool& res){
        if(visit[i] == 2) return;
        if(visit[i] == 1){
            res = false;
            return ;
        }
        visit[i] =1;
        for(int j:adj[i]){
            solve(adj,visit,j,res);
            visit[j] = 2;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>visit(numCourses);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        bool res = true;
        for(int i= 0 ; i<numCourses; i++){
            if(visit[i] == 2) continue; 
            solve(adj,visit,i,res);
            visit[i] = 2;
            if(res == false) return false;
        }
        return true;
    }
};