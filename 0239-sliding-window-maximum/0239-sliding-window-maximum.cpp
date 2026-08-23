class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_ele;
        priority_queue<pair<int,int>> pq;
        int start=0,end = k-1;
        for(int i=0;i<nums.size() ;i++ ){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second <= i-k){
                pq.pop();
            }
            if(i >= k-1)
            max_ele.push_back(pq.top().first);            
        }
        return max_ele;
    }
};