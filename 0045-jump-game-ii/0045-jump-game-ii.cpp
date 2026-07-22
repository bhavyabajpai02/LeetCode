class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n,INT_MAX);
        // dp[0]=0;
        // for(int i=0 ; i<n ; i++){
        //     if(dp[i] == INT_MAX) continue;
        //     for(int j= 1 ; j<=nums[i] and i+j <n ; j++)
        //         dp[i+j] = min(dp[i+j], dp[i]+1 );
        // }
        // return dp[n-1];
        vector<bool>visit(nums.size(),false);
        if(nums.size() == 1) return 0;
        queue<int>q;
        q.push(0);
        int path = 0,minPath = INT_MAX ; 
        while(!q.empty()){
            int a = q.size();
        for(int i=0; i<a; i++){
            int index = q.front();
            q.pop();
            int count = 1;
            // if(index == n-1){

            // }
            while(count <= nums[index] and count + index <n){
                if(count+index == n-1){
                    minPath = min(minPath,path+1);
                    break;
                }
                if(!visit[count+index]){
                q.push(count+index);
                visit[count+index] = true;
                }

                count++;
            }
        }
            path++;
            // minPath = min(minP)
        }
        minPath = min(minPath,path);
        return minPath;
    }
};