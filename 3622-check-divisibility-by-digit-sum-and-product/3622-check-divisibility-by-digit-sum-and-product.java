class Solution {
    public boolean checkDivisibility(int n) {
        int sum =0,prod = 1,org = n;
        while(org>0){
            int a = org%10;
            sum += a;
            prod *= a;
            org /= 10;
        }
        return n%(sum+prod) == 0;
    }
}