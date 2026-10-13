
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        queue<vector<int>> q;

        // Push all land cells into the queue
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // All water or all land
        if(q.empty() || q.size() == row * col) return -1;

        int res = -1;

        while(!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; i++) {
                vector<int> v = q.front();
                q.pop();

                for(auto d : dir) {
                    int nr = v[0] + d[0], nc = v[1] + d[1];

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col
                       && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            res++;
        }

        return res;
    }
};
