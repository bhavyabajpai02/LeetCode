class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        for(auto& i:s){
            if(i == '('){
                stk.push(i);
            }
            else{
                if(!stk.empty() and stk.top() == '('){
                    // popping valid parentheses
                    stk.pop();
                }
                else{
                    stk.push(i);
                }
            }
        }
        return stk.size();
    }
};