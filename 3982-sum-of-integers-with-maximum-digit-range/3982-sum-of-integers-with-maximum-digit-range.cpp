class Solution {
public:
    int findDigitrange(int i){
        int mx = 0,mn =9;
        while(i>0){
            int a = i%10;
            mx = max(mx,a);
            mn = min(mn,a);
            i /=10;
        }
        return mx-mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int res=0,maxRange=0;
        vector<int>range(nums.size());
        for(int i=0; i<nums.size(); i++){
            range[i] = findDigitrange(nums[i]);
            maxRange = max(range[i],maxRange);
        }
        for(int i=0; i<nums.size(); i++){
            if(range[i] == maxRange){
                res+=nums[i];
            }
        }
        return res;
    }
};