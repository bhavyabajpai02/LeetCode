class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        string check= strs[0];
        int k=1;
        if(strs.size() < 2 ){
            return check;
        }
        // while(check == res and k<strs.size()){
        //     if(strs[k] == res){
        //         check = strs[k++];
        //     }
        //     else{
        //         break;
        //     }
        //     k++;
        // }
        if(check != res )
        if(check == res ){
            return res;
        }
        int i=0;
        while(i<check.length())
        {   
            for(int j=1 ; j<strs.size() ; j++){
                if(check[i] != strs[j][i]){
                    return res;
                }
            }
            res += check[i];
            i++;
        }
        return res;
    }
};