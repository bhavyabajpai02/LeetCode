class Solution {
    public boolean solve(String s, int i , int j){
        if(i>=j) return true;
        if(s.charAt(i) == s.charAt(j)){
            return solve (s,i+1,j-1);
        }
        return false;
    }
    public String longestPalindrome(String s) {
        int maxLen = 1,strt = 0;
        for(int i=0 ; i<s.length(); i++){
            for(int j= i+1; j<s.length(); j++){
                if(solve(s,i,j) && j-i+1 > maxLen){
                    maxLen = j-i+1;
                    strt = i;
                }
            }
        }
        return s.substring(strt,strt+maxLen);
    }
}