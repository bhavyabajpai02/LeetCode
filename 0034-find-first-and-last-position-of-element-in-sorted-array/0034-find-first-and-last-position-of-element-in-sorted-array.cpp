class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int back=-1,front =-1, n= nums.size();
        for(int i=0 ; i<n ; i++ ){
            if(nums[i] == target){
                front = i;
                break;
            }
        }
        for(int i=0 ; i<n ; i++ ){
            if(nums[n-1-i] == target){
                back = n-1-i;
                break;
            }
        }
        if(front == -1 and back == -1){
            return {-1,-1};
        }
        return {front,back};
    }
};