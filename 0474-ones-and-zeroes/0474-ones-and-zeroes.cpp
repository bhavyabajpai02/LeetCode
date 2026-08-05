class Solution {
public:

    int recur(int i , int m, int n ,vector<string>&strs,vector<vector<vector<int>>> &dp){
        if(i == strs.size()){
            return 0;
        }
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        int zero=0,ones = 0;
        for(auto& j: strs[i]){
            if(j == '0') zero++;
            else ones++;
        }
        int pick=0, unpick = recur(i+1,m,n,strs,dp);
        if(m>=zero and n>=ones){
            pick = 1+recur(i+1,m-zero,n-ones,strs,dp);
        }
        return dp[i][m][n] = max(pick,unpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        // int res=0;
        return recur(0,m,n,strs,dp);
    }
};