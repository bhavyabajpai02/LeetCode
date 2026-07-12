class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // 1st approach
        // map<int,vector<int>> mp;
        // vector<int> res(arr.size());
        // vector<pair<int,int>>v;
        // for(int i=0 ; i<arr.size(); i++){
        //     mp[arr[i]].push_back(i);
        // }
        // int rank=1;
        // for(auto i:mp){
        //     for(int j=0; j<i.second.size(); j++){
        //         res[i.second[j]] = rank;
        //     }
        //     rank++;
        // }
        // return res;     

        map<int,int>mp;
        for(auto& i:arr){
            mp[i];
        }  
        int rank =1;
        for(auto&i:mp){
            i.second = rank++;
        }
        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};