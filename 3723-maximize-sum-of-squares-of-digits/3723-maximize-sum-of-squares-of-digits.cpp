class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int digit = 9,total = 0,count = 0;
        string s ="";
        while(count<num){
            if(total+digit <= sum){
                s += to_string(digit);
                total += digit;
                count++;
            }
            else{
                digit--;
            }
        }
        
        return total == sum ? s:"";
    }
};