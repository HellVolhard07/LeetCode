class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> ans(m, vector<int> (n, INT_MAX));
        pq.push({0, 0, 0});
        ans[0][0] = 0;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!pq.empty()) {
            vector<int> node = pq.top();
            pq.pop();
            int dist = node[0];
            int x = node[1];
            int y = node[2];
            if(x == m - 1 and y == n - 1) return dist;
            for(int i = 0 ; i < 4 ; i++) {
                int nrow = x + dx[i];
                int ncol = y + dy[i];
                if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n) {
                    int ndist = max(dist, abs(heights[nrow][ncol] - heights[x][y]));
                    if(ndist < ans[nrow][ncol]) {
                        ans[nrow][ncol] = ndist;
                        pq.push({ndist, nrow, ncol});
                    }
                }
            }
        }
        return 0;
    }
};