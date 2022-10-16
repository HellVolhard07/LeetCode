//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<vector<int>> &ans, int row, int col) {
        visited[row][col] = true;
        
        
    }
    
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<bool>> visited(n, vector<bool> (m, false));
	    vector<vector<int>> ans(n, vector<int> (m, 0));
	    queue<pair<pair<int, int>, int>> q;
	    for(int i = 0 ; i < n ; i++) {
	        for(int j = 0 ; j < m ; j++) {
	            if(grid[i][j] == 1) {
	                visited[i][j] = true;
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    while(!q.empty()) {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        
	        for(int i = -1 ; i <= 1 ; i++) {
	            for(int j = -1 ; j <= 1 ; j++) {
	                if(i != j and i != -j) {
	                    int nrow = row + i;
	                    int ncol = col + j;
	                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 0 and !visited[nrow][ncol]) {
	                        visited[nrow][ncol] = true;
	                        ans[nrow][ncol] = d + 1;
	                        q.push({{nrow, ncol}, d + 1});
	                    }
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends