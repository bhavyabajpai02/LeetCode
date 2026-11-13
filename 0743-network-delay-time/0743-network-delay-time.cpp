
class Solution {
public:
    void solve(int curr, vector<int>& dist,
               vector<vector<pair<int,int>>>& adj) {

        for (auto nei : adj[curr]) {
            int node = nei.first;
            int wt = nei.second;

            if (dist[curr] + wt < dist[node]) {
                dist[node] = dist[curr] + wt;
                solve(node, dist, adj);
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto i : times) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        solve(k, dist, adj);

        int res = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;

            res = max(res, dist[i]);
        }

        return res;
    }
};
