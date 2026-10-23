class Solution {
public:
    int solve(vector<int>&nums,int i, int sum, int n, int target,map<pair<int,int>,int>&dp){
        if(i == n) {
            return sum == target;
        }
        if(dp.count({i,sum})){
            return dp[{i,sum}];
        }
        int plus = solve(nums,i+1,sum+nums[i],nums.size(),target,dp);
        int minus = solve(nums,i+1,sum-nums[i],nums.size(),target,dp); 
        return dp[{i,sum}] = plus+minus;      
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>dp;
        return solve(nums,0,0,nums.size(),target,dp);
        // return count;
    }
};