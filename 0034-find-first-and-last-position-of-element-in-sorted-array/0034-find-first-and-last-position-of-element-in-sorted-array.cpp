class Solution {
public:
    int endIndex(vector<int>&nums,int target){
        int ans = -1,l = 0 , r = nums.size() -1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(nums[mid] == target){
                ans = mid;
                l = mid+1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }else if(nums[mid] < target){
                l = mid+1;
            }
        }
        return ans;
    }
    int firstIndex(vector<int>&nums,int target){
        int ans = -1,l = 0 , r = nums.size() -1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(nums[mid] == target){
                ans = mid;
                r = mid-1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }else if(nums[mid] < target){
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        // int back=-1,front =-1, n= nums.size();
        // for(int i=0 ; i<n ; i++ ){
        //     if(nums[i] == target){
        //         front = i;
        //         break;
        //     }
        // }
        // for(int i=0 ; i<n ; i++ ){
        //     if(nums[n-1-i] == target){
        //         back = n-1-i;
        //         break;
        //     }
        // }
        // if(front == -1 and back == -1){
        //     return {-1,-1};
        // }
        // return {front,back};
        return {firstIndex(nums,target),endIndex(nums,target)};
    }
};