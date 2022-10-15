//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();
            for(int i = -1 ; i <= 1 ; i++) {
                for(int j = -1 ; j <= 1 ; j++) {
                    int nrow = crow + i;
                    int ncol = ccol + j;
                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == '1' and !visited[nrow][ncol]) {
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for(int row = 0 ; row < n ; row++) {
            for(int col = 0 ; col < m ; col++) {
                if(!visited[row][col] and grid[row][col] == '1') {
                    ans++;
                    bfs(grid, visited, row, col);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends