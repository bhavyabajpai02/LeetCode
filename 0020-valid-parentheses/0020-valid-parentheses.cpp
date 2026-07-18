class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto& i:s){
            if(i=='(' or i == '[' or i == '{' ){
                stk.push(i);
            }
            else{
                if(stk.empty()) return false;
                if((stk.top() == '(' and i == ')') or (stk.top() == '{' and i == '}') or (stk.top() == '[' and i == ']')){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};