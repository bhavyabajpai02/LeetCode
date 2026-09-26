class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto s:knowledge){
            mp[s[0]] = s[1]; 
        }
        string r = "";
        string res="";
        int i=0;
        while( i<s.length()){
            if(s[i] == '('){
                i++;
                while(i<s.length() and s[i] != ')'){
                    r+=s[i];
                    i++;
                }
                if(mp.contains(r)){
                   res += mp[r];
                }
                else{
                    res += "?";
                }
                r="";
                i++;
            }
            if(i<s.length() and s[i] != '(')
            res += s[i];
            // else
            if(s[i] != '(')
            i++;
        }
        return res;
    }
};