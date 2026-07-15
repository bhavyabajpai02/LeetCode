class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=1;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto j:nums){
            pq.push(j);
        }

        while(!pq.empty()){
            if(pq.top() > i){
                return i;
            }
            else if(pq.top() == i){
            i++;
            }
            pq.pop();
        }
        return i++;
    }
};