class Solution {
public:
    void solve(int& count, vector<int>&nums,int i, int sum, int n, int target){
        if(i >= n) {
        if(sum == target){
            count++;
        }
        return;
        }
        solve(count,nums,i+1,sum+nums[i],nums.size(),target);
        solve(count,nums,i+1,sum-nums[i],nums.size(),target);        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        solve(count,nums,0,0,nums.size(),target);
        return count;
    }
};