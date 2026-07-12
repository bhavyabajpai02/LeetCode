class Solution {
public:
    bool possibleAns(vector<int>& piles, int h ,int k){
        long long hours = 0;
        for(int& i:piles){
            hours += (i+k-1)/k;
            // cout<<hours<<endl;
        }
        return hours<= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = *max_element(piles.begin(),piles.end());
        while(low<high){
            int mid = low + (high - low)/2;
            if(possibleAns(piles,h,mid)){
                high = mid ;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
};