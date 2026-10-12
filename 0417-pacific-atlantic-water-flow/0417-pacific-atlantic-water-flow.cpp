class Solution {
public:
    void dfs(int r, int c, int& row, int& col,vector<vector<int>>&heights,vector<vector<bool>>&v,vector<vector<int>>&dir){
        // if(r == row or c == col) return;
        if (r < 0 || r >= row || c < 0 || c >= col || v[r][c])
            return;
        v[r][c] = true;
        for(auto i:dir){
            if(r+i[0] < row and r+i[0] >=0 and c+i[1] < col and c+i[1] >=0 and heights[r][c] <= heights[r+i[0]][c+i[1]]){

                dfs(r+i[0],c+i[1],row,col,heights,v,dir);

            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(),col = heights[0].size(); 
        vector<vector<bool>>a(row, vector<bool>(col)); 
        vector<vector<bool>>p(row, vector<bool>(col)); 

        vector<vector<int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
        for(int i=0; i<col; i++){
            dfs(0,i,row,col,heights,p,dir);
            dfs(row-1,i,row,col,heights,a,dir);
        }
        for(int i=0; i<row; i++){
            dfs(i,0,row,col,heights,p,dir);
            dfs(i,col-1,row,col,heights,a,dir);
        }

        vector<vector<int>> res;
        for(int i = 0 ; i<row; i++){
            for(int j = 0 ;j<col ; j++){
                if(p[i][j] and a[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};