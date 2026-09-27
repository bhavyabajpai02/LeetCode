class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1,j = t.length() -1;
                int smiss = 0;
                int tmiss = 0;
        while(i >= 0 or j>= 0){
            while( i>= 0 ){
                if(i>=0 and s[i] =='#'){
                    i--;
                    smiss++;
                }
                else if(smiss >0){
                    i--;
                    smiss--;
                }
                else {
                    break;
                }
            }
            while( j>= 0 ){
                if(j>=0 and t[j] =='#'){
                    j--;
                    tmiss++;
                }
                else if(tmiss >0){
                    j--;
                    tmiss--;
                }
                else {
                    break;
                }
            }
            if(i <0 and j<0 ) return true;
            if(i<0 or j<0) return false;
            if(s[i] != t[j]) return false;
            i--;
            j--;
        } 
        return true;
    }
};