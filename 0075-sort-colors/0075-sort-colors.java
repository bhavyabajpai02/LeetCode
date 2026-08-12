class Solution {
    public void sortColors(int[] nums) {
        if(nums.length  <= 1) return;
        int l = 0 , mid = 0 , r = nums.length-1;
        while(mid <= r){
            if(nums[mid] == 0) {
                int temp = nums[mid];
                nums[mid] = nums[l];
                nums[l] = temp;
                // if(l+1 <= mid)
                    l++;
                    mid++;
            }
            else if(nums[mid] == 2) {
                int temp = nums[mid];
                nums[mid] = nums[r];
                nums[r] = temp;
                // if(r-1 >= mid){
                    r--;
                // }
            }
            else if(nums[mid] == 1)
            // else
            mid++;
        }
        
    }
}