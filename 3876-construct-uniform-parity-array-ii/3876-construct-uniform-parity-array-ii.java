class Solution {
    public boolean uniformArray(int[] nums1) {
        int mini = Integer.MAX_VALUE;
        boolean checkOdd = false;
        for(int i = 0 ; i<nums1.length; i++){
            mini = Math.min(mini,nums1[i]); 
            if(nums1[i] % 2 != 0) checkOdd = true;
        }
        return (mini%2== 0 && checkOdd == true) ? false: true;
    }
}