class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool check = true;
        for(int i=0 ; i<bits.size() ;i++){
            if(bits[i] == 1){
                i++;
                check = false;
            }
            else{
                check = true;
            }
        }
        return check;
    }
};