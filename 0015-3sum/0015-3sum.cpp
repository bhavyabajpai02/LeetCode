class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int sum = -(nums[i] + nums[j]);
                bool found = binary_search(nums.begin() + j + 1, nums.end(), sum);
                if(found) {
                        int a = max(nums[i], max(nums[j], sum));
                        int b = min(nums[i], min(nums[j], sum));
                        int c = nums[i] ^ nums[j] ^ sum ^ a ^ b;
                        st.insert({a, c, b});
                }
            }
        }

        vector<vector<int>> res(st.begin(), st.end());

        return res;
    }
};