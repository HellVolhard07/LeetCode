class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if(i >= m || j>=n) return 1e9;
        if(i == m - 1 && j == n - 1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = grid[i][j] + helper(i, j + 1, grid, m, n, dp);
        int down = grid[i][j] + helper(i + 1, j, grid, m, n, dp);
    
        return dp[i][j] = min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return helper(0, 0, grid, m, n, dp);
    }
};