class Solution {
    void recurr(int [][] isConnected , boolean []visited,int i,int n){
        // if(i> n) return;
        for(int j=0 ; j<n ; j++){
            if(!visited[j] && isConnected[i][j] == 1){
                visited[j] = true;
                recurr(isConnected,visited,j,n);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean []visited = new boolean[n];
        // visited.fill(false);
        int province=0;
        for(int i=0; i<n ; i++){
            if(!visited[i]){
                province++;
                visited[i] = true;
                recurr(isConnected,visited,i,n);
            }
        }
        return province;
    }
}