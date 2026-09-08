class Solution {
    // 1,000
    // 10,000
    // 100,000
    public int countCommas(int n) {
        if(n < 1000) return 0;
        if(n >= 1000 && n < 10000) return n- 999;
        else if(n >= 10000 && n <100000) return 9000 + (n-9999) ;
        return 99000+(n-99999); 
    }
}