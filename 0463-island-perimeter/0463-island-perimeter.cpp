class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int c = 0,m= grid.size(), n= grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    if(i == 0) c+=1;
                    if(j==0) c+= 1;
                    if(i ==m-1) c+=1;
                    if(j ==n-1) c+=1;
                    if(i+1 <m and grid[i+1][j] == 0) c+=1;
                    if(i-1 >= 0  and grid[i-1][j] == 0) c+=1;
                    if(j+1 <n and grid[i][j+1] == 0) c+=1;
                    if(j-1 >= 0  and grid[i][j-1] == 0) c+=1;
                    cout<<c<<endl;
                }
            }
        }
        return c;
    }
};