class Solution {
public:
    string removeKdigits(string num, int k){
        if(k>=num.length()) return "0";
        // if(k == 0){
        //     return num;
        // }
        stack<char>stk;
        stk.push(num[0]);
        int i;
        for(i=1; i<num.length() ; i++){
            while(!stk.empty() and stk.top()> num[i] and k){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(!stk.empty() and k--){
            stk.pop();
        }
        string res="";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        
        bool p = true;
        for(int i= res.length()-1;i>=0; i--){
            if(p){
                if(res[i] == '0'){
                res.pop_back();
                }                    
                else{
                    p = false;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res ==""? "0":res;
    }
};