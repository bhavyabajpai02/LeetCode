class Solution {
    public void solve(int i, int j , int m, int n , char[][]grid,int[][] dir,boolean[][] visited){
        if(i< 0 || i == m || j<0 || j==n ) return ;
        if(grid[i][j] == '0' || visited[i][j] == true) return;
        visited[i][j] = true;
        for(int[] k: dir){
            solve(i+k[0],j+k[1],m , n , grid,dir, visited);
        }
    }
    public int numIslands(char[][] grid) {
        int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}};
        int island= 0 ;
        int m = grid.length ,n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        for(int i = 0 ; i< grid.length; i++){
            for(int j = 0 ; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    solve(i,j,m,n,grid,dir,visited);
                    island++;
                }
            }
        }  
        return island;
    }
}