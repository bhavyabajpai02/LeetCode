
class Solution {
public:
    int solve(int i, vector<int>& coins, int n, int amount,vector<vector<int>>&dp) {
        if(amount == 0) return 1;
        if(i >= n) return 0;
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int notTake = solve(i + 1, coins, n, amount,dp);
        int take = 0;
        if(coins[i] <= amount) {
            take = solve(i, coins, n, amount - coins[i],dp);
        }
        return dp[i][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0, coins, n, amount,dp);
    }
};
