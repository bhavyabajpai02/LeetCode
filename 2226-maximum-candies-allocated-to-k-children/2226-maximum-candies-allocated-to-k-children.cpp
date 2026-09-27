class Solution {
public:
    bool possible(long long mid, vector<int>& candies, long long k){
        long long children = 0;
        for(int i=0 ; i<candies.size() ; i++){
             children += candies[i]/mid;
             if(children >= k ) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(),candies.end(), 0LL);
        if(total < k) return 0;
        long long left = 1,right = total/k;
        int ans  =0;
        while(left <= right){
            long long mid = left + (right-left)/2;
            if(possible(mid,candies,k)){
                ans = mid;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return ans;
    }
};