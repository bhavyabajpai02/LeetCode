class Solution {
public:
    // void solve(vector<vector<int>>&grid, vector<vector<int>>&dir,int& one, int& min,int& n, int&m,vector<vector<bool>>&visit,int i,int j){
    //     if(i>=n or j>=m) return;
    //     if(visit[i][j]) return;
    //     visit[i][j] = true;
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
        int res = 0,ones = 0;
        // for(int i=0 ; i<grid.size(); i++){
        //     for(int j=0 ; j<grid[0].size();j++){
        //     }
        // }
        int n = grid.size(),m = grid[0].size();
        // vector<vector<bool>>visit(n,vector<bool>(m,false));
        // for(int i=0; i<grid.size(); i++){
        //     for(int j=0; j<grid.size(); j++){
        //         if(grid[i][j] == 2){
        //             int one = 0,min = 0;
        //             solve(grid,dir,one,min,n,m,visit,i,j);
        //             if(ones == one){
        //                 res = min(res,min);
        //             }
        //         }
        //     }
        // }
        queue<vector<int>>q;
        for(int i=0 ; i<n; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
                else if(grid[i][j] == 1) ones++;
            }
        }
        if(ones == 0) return 0;
        while(!q.empty()){
            vector<int> v = q.front();
            q.pop();
            // min++;
            for(auto i:dir){
                if(i[0]+v[0] >=0 and i[0]+v[0] < n and i[1]+v[1] >=0 and i[1]+v[1] < m and grid[i[0]+v[0]][i[1]+v[1]] == 1  ){
                    // visit[i[0]+v[0]][i[1]+v[1]] = true;
                    grid[i[0]+v[0]][i[1]+v[1]] = 2;
                    q.push({i[0]+v[0],i[1]+v[1],v[2]+1});
                    ones--;
                    res = max(res,v[2]+1);
                }
            }
        }
        return ones != 0?-1:res;
    }
};