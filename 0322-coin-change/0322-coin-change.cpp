class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // if(amount == 0) return 0;
        // int coin = INT_MAX,ncoin=0;
        // priority_queue<int>orgpq;
        // for(auto& i:coins){
        //     orgpq.push(i);
        // }
        // priority_queue<int>pq = orgpq;
        // int var= orgpq.top(),sum =0;
        // while(!orgpq.empty()){
        //     if(pq.empty() or (sum+var == amount)){
        //         if(!pq.empty() and sum+var== amount)
        //         coin = min(coin,ncoin+1);
        //         orgpq.pop();
        //         if(!orgpq.empty()){
        //             var = orgpq.top();
        //             sum =0;
        //             pq = orgpq;
        //             ncoin =0;
        //         }
        //     }
        //     else if(sum+var >amount){
        //         pq.pop();
        //         if(!pq.empty()){
        //             var = pq.top();
        //         }
        //     }
        //     else{
        //         sum+=var;
        //         ncoin++;
        //     }

        // }
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (auto& i : coins) {
            for (int j = i; j <= amount; j++) {
                if (dp[j - i] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - i] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};