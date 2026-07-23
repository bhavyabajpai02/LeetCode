class Solution {
public:
    bool isSubsequence(string s, string t) {
        if( t.length() < s.length()) return false;
        int i= 0,j = 0;
        while(i<s.length() and j< t.length()){
            while(j<t.length() and s[i] != t[j]){
                j++;
            }
            if(j == t.length()){
                return false;
            }
            i++;
            j++;
        }
        return i == s.length();
    }
};