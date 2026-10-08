class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        stack<char>stk;
        for(char c:s){
            if( c =='(' and stk.empty()){
                stk.push(c);
            }
            else if( c == '(' and !stk.empty()){
                stk.push(c);
                res +=c;
            }
            else{
                if(!stk.empty()){
                    stk.pop();
                    if(!stk.empty())
                    res += ')';
                }
            }
        }
        return res;
    }
};