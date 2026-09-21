class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> res;
      unordered_map<int,int> times;
      for(auto i: nums)
      {
        times[i]++;
      }
     
      for(auto &i : times)
      {
      if (i.second > (nums.size()/3) )
      {
        res.push_back(i.first);
      }
      }
      return res;
    }
};