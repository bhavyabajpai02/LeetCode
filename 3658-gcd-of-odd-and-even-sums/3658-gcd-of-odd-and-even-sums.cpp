class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0,sumEven = 0;
        int count = 1;
        while(n--){
            sumOdd += count;
            count++;
            sumEven += count;
            count++;
        }
        return gcd(sumOdd,sumEven);
    }
};