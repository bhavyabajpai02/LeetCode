class Solution {
public:
    void backtrack(vector<vector<int>>&res, vector<int>&path,int start,vector<int>&candidates,int target){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i= start;i<candidates.size(); i++){
            if(i>start and candidates[i-1] == candidates[i] ) continue;
            if(candidates[i]>target) break;
            path.push_back(candidates[i]);
            backtrack(res,path,i+1,candidates,target-candidates[i]);
            path.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>path;
        sort(candidates.begin(),candidates.end());
        backtrack(res,path,0,candidates,target);
        return res;
    }

};