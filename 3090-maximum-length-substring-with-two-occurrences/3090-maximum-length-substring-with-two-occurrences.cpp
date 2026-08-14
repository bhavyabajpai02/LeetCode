class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen = 0 , i=0, j= 0;
        unordered_map<char,int> mp;
        // queue<char>q;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp[s[j]] > 2){
                while( mp[s[j]] > 2 and i < s.length()){
                    mp[s[i]]--;
                    i++;
                }
            }
           
            // cout<<len<<" i"<<i<<" j"<<j<<endl;
            maxLen = max(j-i+1,maxLen);
            j++; 
        }
        return maxLen;
    }
};