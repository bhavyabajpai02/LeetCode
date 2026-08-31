class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        return solve(s,0,n-1,dp);

    }
    private int solve(String s, int left, int right, int[][] dp){
        if(left >= right) return 0;
        if(dp[left][right] != 0){
            return dp[left][right];
        }
        if(s.charAt(left) == s.charAt(right)) 
            dp[left][right] = solve(s,left+1,right-1,dp);
        else
            dp[left][right] = 1+ Math.min(solve(s,left+1,right,dp),solve(s,left, right-1, dp));
        return dp[left][right];
    }
}