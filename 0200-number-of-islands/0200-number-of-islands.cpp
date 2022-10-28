class Solution {
public:
    
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited, int m, int n) {
        visited[row][col] = true;
        for(int i = -1 ; i <= 1 ; i++) {
            for(int j = -1 ; j <= 1 ; j++) {
                if(i != j and i != -j) {
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == '1' and !visited[nrow][ncol]) {
                        dfs(nrow, ncol, grid, visited, m, n);
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int ans = 0;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == '1' and !visited[i][j]) {
                    dfs(i, j, grid, visited, m , n);
                    ans++;
                }
            }
        }
        return ans;
    }
};