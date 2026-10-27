class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>winner,looser;
        for(auto i:matches){
            winner[i[0]]++;
            looser[i[1]]++;
        }
        vector<vector<int>>res(2);
        for(auto i:winner){
            if(!looser.count(i.first)) res[0].push_back(i.first);
        }
        for(auto i:looser){
            if(i.second == 1) res[1].push_back(i.first);
        }
        return res;
    }
};