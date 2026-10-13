class Solution {
public:
    void dfs(queue<vector<int>>&q, int i, int j,int row, int col, vector<vector<int>>&dir, vector<vector<int>>&grid, vector<vector<bool>>&visited){
        if(i<0 or i>=row or j<0 or j>= col or visited[i][j] == true ) return;
        if(grid[i][j] == 1){
            visited[i][j] = true;
            q.push({i,j});
            for(auto d:dir){
                // int nr = i+d[0],nc = 
                dfs(q, i+d[0] , j+d[1] ,row , col, dir, grid,visited);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        // vector<vector<int>>first;
        vector<vector<bool>>visited(row,vector<bool>(col));
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        bool found = false;
        queue<vector<int>>q;
        for(int i = 0; i<row ; i++){
            for(int j= 0 ; j<col ; j++){
                if(grid[i][j] == 1){
                    dfs(q, i , j ,row , col, dir, grid,visited);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        // for(int i = 0 ; i<first.size(); i++){
        //     q.push(first[i]);
        // }
        bool check = false;
        int res = 0; 
        // for(auto i:first){
        //     cout<<i[0] <<" "<<i[1]<<endl;
        // }
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i<n ; i++){
                vector<int>v = q.front();
                q.pop();
                for(auto d:dir){
                    int nr = v[0]+d[0], nc = v[1]+d[1];
                    if(nr >=0 and nr < row and nc>=0 and nc< col and !visited[nr][nc]){
                        if(grid[nr][nc] == 1){
                            check = true;
                            break;
                        }
                        else {
                            visited[nr][nc] = true;
                            q.push({nr,nc});
                        }
                    }
                }
                if(check) break;
            }
        if(check) break;
        res++;
        }
    return res;
    
    }
};