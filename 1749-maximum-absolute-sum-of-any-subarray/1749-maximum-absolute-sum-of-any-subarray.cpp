class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n ; i++){
            nums[i] += nums[i-1];
        }
        int max = *max_element(nums.begin(),nums.end());
        int min = *min_element(nums.begin(),nums.end());
        if(max < 0) return abs(min);
        if(min >= 0) return abs(max);
        return abs(max)+abs(min);
    }
};