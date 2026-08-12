class Solution {
    public int[] cycleLengthQueries(int n, int[][] queries) {
        int m = queries.length;
        int[] ans= new int[m];
        for(int i=0 ; i<m ; i++){
            // int maxi = Math.max(queries[i][0],queries[i][1]);
            int turns = 1;
            while(queries[i][0] != queries[i][1] ){
                turns++;
                if(queries[i][0]  > queries[i][1]){
                    queries[i][0] /= 2;
                   
                }
                else{
                    queries[i][1] /= 2;
                }
                
            }
            ans[i] = turns;
        }
        return ans;
    }
}