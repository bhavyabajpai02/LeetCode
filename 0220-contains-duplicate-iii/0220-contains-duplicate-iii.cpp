class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> a;
        for(int i=0; i<nums.size(); i++){
            if(i > indexDiff){
                a.erase(nums[i-indexDiff-1]);
            }
                auto ptr = a.lower_bound((long long)nums[i] - valueDiff);
                if(ptr != a.end() and *ptr<= (long long)nums[i]+valueDiff){
                    return true;
                }
                a.insert(nums[i]);
        }
        return false;
    }
};