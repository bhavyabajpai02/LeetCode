class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>indeg(numCourses);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        queue<int>q;
        for(int i= 0 ; i<indeg.size(); i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        int count =0 ;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            count++;
            for(int j:adj[i]){
               indeg[j]--;
               if(indeg[j] == 0)
                q.push(j);
            }
        }
        return count == numCourses;
    }
};