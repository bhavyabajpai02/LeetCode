class Solution {
    static void swap(int[] nums, int i ,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public int firstMissingPositive(int[] nums) {
        // Arrays.sort(nums);
        int val =1;
        // while(i<nums.length && nums[i] <= 0){
        //     i++;
        // }
        // if(i == nums.length) return 1;
        for(int i = 0 ; i<nums.length; i++){
            while(nums[i]>0 && nums[i]<= nums.length && nums[nums[i] - 1] != nums[i]){
               int ci = nums[i]-1;
               swap(nums,i,nums[i]-1);
            }
        }
        for(int i=0 ; i<nums.length; i++){
            if(nums[i] != i+1) return i+1;
        }
        return nums.length + 1;
    }
}