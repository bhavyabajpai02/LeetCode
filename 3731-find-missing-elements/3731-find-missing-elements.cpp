class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>res;
        // int i= nums[0]+1;
        int n=nums.size();
        // int j=1;
        // while(i<nums[n-1] and j<n){
        //     if(i != nums[j] ){
        //         res.push_back(i);
        //     }
        //     else{
        //         j++;  
        //     }
        //         i++;
        // }
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i=mini+1; i<maxi; i++){
            if(!st.count(i)){
                res.push_back(i);
            }
        }
    return res;
    }
};