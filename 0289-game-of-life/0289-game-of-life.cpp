class Solution {
public:
    // bool check (vector<vector<int>>&board,int i, int j,vector<vector<int>>&dir,int n,int m){
        
    // }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>dir{{1,0},{0,1},{1,1},{1,-1},{-1,1},{-1,0},{0,-1},{-1,-1}};
        vector<vector<int>>v = board;
        int m = board.size(), n= board[0].size();
        int count = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0; j<n ; j++){
                int count = 0;
                for(auto &d:dir){
                    if(i+d[0] >= 0 and i+d[0] < m and j+d[1] < n and j+d[1] >= 0 and v[i+d[0]][j+d[1]] == 1){
                        count++;
                    }
                }
                // cout<<count<<" ";
                if((count<2 or count>3) and v[i][j] == 1){
                    board[i][j] = 0;
                }
                if(count == 3 and v[i][j] == 0) board[i][j] = 1;

            }
            // cout<<endl;
        }
        // return board;
    }
};