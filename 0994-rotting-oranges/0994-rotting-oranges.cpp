class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<bool>> visited(n, vector<bool> (m, false));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m  ; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    // visited[i][j] = true;
                }
            }
        }
        int ans = 0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans = max(ans, t);
            
            for(int i = -1 ; i <= 1 ; i++) {
                for(int j = -1 ; j <= 1 ; j++) {
                    if(i != j and i != -j) {
                        int nrow = row + i;
                        int ncol = col + j;
                        if(nrow >=0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1) {
                            grid[nrow][ncol] = 2;
                            q.push({{nrow, ncol}, t + 1});
                        }
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};