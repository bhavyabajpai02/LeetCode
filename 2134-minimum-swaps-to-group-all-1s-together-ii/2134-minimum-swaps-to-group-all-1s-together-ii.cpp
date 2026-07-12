class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n= nums.size(),ones = 0;
        for(auto& i:nums){
            if(i) ones++;
        }
        int zeros = 0 ; 
        // First window
        for(int i=0; i<ones; i++){
            if(nums[i] == 0){
                zeros++;
            }
        }
        int l=0, res = zeros;
        for (int r= ones;r< n+ones; r++){
            if(nums[l] == 0){
                zeros--;
            }
            if(nums[r%n] == 0){
                zeros++;
            }
            res = min(res,zeros);
            l++;
        }
        return res;
    }
};