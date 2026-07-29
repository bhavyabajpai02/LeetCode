class Solution {
public:
    // int backtrack(int& valid, string& s,int start){
    //     if(start == s.length()){
    //         valid++;
    //      return ;
    //     }
    //     if(s[start] == '0') return ;
    //     backtrack(valid,s,start+1);
    //     if(start+1 <s.length()){
    //         string t = "";
    //         t += s[start];
    //         t += s[start+1];
    //         if(stoi(t) <= 26)
    //         backtrack(valid,s,start+2);
    //     }
    // }
    int solve(string& s , int start , vector<int>&dp){
        if(start == s.length()) return 1;
        if(s[start] == '0') return 0;
        if(dp[start] != -1) return dp[start]; 
        int ways=0;
         ways += solve(s, start + 1, dp);

        // Take two digits
        if(start + 1 < s.length()) {

            int num = (s[start]-'0')*10 + (s[start+1]-'0');

            if(num >= 10 && num <= 26)
                ways += solve(s, start + 2, dp);
        }

        return dp[start] = ways;
    }
    int numDecodings(string s) {
        int valid = 0,start =0;
        // string t = "";
        vector<int>dp(s.length()+1,-1);
        // int res= backtrack(valid,s,start);
        return solve (s,start,dp);
        // return valid;

    }
};