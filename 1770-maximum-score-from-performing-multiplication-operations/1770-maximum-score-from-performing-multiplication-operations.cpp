class Solution {
public:
    int solve(vector<int>&nums,vector<int>& multipliers,int i,int l,int n ,int m,vector<vector<int>>&memo){
        if(i == m){
            return 0;
        }
        int r = n-i-1+l;
        if(memo[i][l] != -1){
            return memo[i][l];
        }
        int left = multipliers[i]*nums[l] + solve(nums,multipliers,i+1,l+1,n,m,memo);
        int right = multipliers[i]*nums[r] + solve(nums,multipliers,i+1,l,n,m,memo);
        memo[i][l] = max(left,right);
        return memo[i][l];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>>memo(m+1,vector<int>(m+1,-1));
        return solve(nums,multipliers,0,0,n,m,memo);
    }
};