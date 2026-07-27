class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int> res;
        for(auto i:nums){
            if( i != val){
                res.push_back(i);
            }
        }
        nums.clear();
        for(auto i:res){
            nums.push_back(i);
        }
        return nums.size();
    }
};