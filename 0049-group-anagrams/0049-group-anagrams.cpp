class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string,vector<string>> mp;
      for(auto& i: strs)
      {
        string b=i;
        sort(b.begin(),b.end());
        mp[b].push_back(i);
      }  
      vector<vector<string>> vc;
      for(auto& i: mp)
      {
        vc.push_back(i.second);
      }
      return vc;
    }
};