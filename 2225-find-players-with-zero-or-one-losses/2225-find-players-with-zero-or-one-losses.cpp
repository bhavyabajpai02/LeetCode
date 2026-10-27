class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>looser;
        for(auto i:matches){
            looser[i[1]]++;
        }
        vector<vector<int>>res(2);
        for(auto i:matches){
            if(!looser.count(i[0])){
                res[0].push_back(i[0]);
                looser[i[0]] = 2;
            }
            if(looser[i[1]] == 1){
                res[1].push_back(i[1]);
            }
        }
        sort(res[0].begin(),res[0].end());
        sort(res[1].begin(),res[1].end());
        return res;
    }
};