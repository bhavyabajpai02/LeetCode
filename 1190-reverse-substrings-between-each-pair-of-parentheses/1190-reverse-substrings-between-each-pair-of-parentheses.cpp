class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '(' or isalpha(s[i])){
                stk.push(s[i]);
            }
            else{
                string r = "";
                while(stk.top() != '('){
                    r+=stk.top();
                    stk.pop();
                }
                stk.pop();
                for(int j=0 ; j<r.length() ; j++){
                    stk.push(r[j]);
                }
            }
        }
        string res ="";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};