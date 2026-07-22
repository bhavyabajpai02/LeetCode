class Solution {
public:
    string smallestSubsequence(string s) {
        stack<int>stk;
        vector<int>count(26,0);
        vector<bool>check(26,false);
        for(int i = 0 ; i<s.length(); i++){
            count[s[i]-'a']++;
        }
        for(auto &i:s){
            count[i-'a']--;
            if(check[i-'a']){
                continue;
            }
            while(!stk.empty() and stk.top() > i and count[stk.top()-'a']>0){
                char c = stk.top();
                stk.pop();
                // count[c-'a']--;

                check[c-'a'] = false;
            }
            // if(count[stk.top()-'a'] == 1 and check[i-'a']){
            //     count[stk.top()] = 0 ;
            // }
            stk.push(i);
            check[i-'a']= true;
        }
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};