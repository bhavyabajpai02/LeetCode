class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int res =0;
        unordered_map<char,vector<int>> mp;
        for(int i= 0 ; i<s.length(); i++){
            mp[s[i]].push_back(i);
        }
        int k = 0;
        bool flag;
        for(auto& i: words){
            int j = 0 , k = 0;
            while(j<i.length()){
            flag = false;
                auto &vec = mp[i[j]];
                auto it = lower_bound(vec.begin(), vec.end(), k);
                if(it == vec.end()){
                    flag = false;
                    break;
                }
                flag = true;
                k = *it + 1;
                // else break;    
                j++;
            }
            if(flag and j == i.length()) res++;
        }
        
        return res;
    }
};