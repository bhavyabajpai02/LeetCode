class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>&dir,int i,int j,int row ,int col){
        board[i][j] = 'V';
        for(auto& k: dir){
            if(i+k[0] >=0 and i+k[0]< row and j+k[1] >=0 and j+k[1] < col and board[i+k[0]][j+k[1]] == 'O'){
                dfs(board,dir,i+k[0],j+k[1],row,col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size(),col = board[0].size();
        // 1st row
        int i=0,j=0;
        vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
        for(; j<col ; j++){
            if(board[i][j] == 'O'){
                dfs(board,dir,i,j,row,col);
            }
        }
        // last col
        j= j-1;
        for(; i<row ; i++){
            if(board[i][j] == 'O'){
                dfs(board,dir,i,j,row,col);
            }
        }

        // last row
        i = i-1;
        for(; j>=0 ; j--){
            if(board[i][j] == 'O'){
                dfs(board,dir,i,j,row,col);
            }
        }
        j=0;
        // first col
        for(; i>=0 ; i--){
            if(board[i][j] == 'O'){
                dfs(board,dir,i,j,row,col);
            }
        }

        for(int i =0 ; i<row; i++){
            for(int j= 0 ; j<col ; j++){
                if(board[i][j] == 'V'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';

                }
            }
        }
    }
};