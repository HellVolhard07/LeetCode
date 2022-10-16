//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    void bfs(vector<vector<int>> &image, vector<vector<bool>> &visited, int row, int col, int color) {
        int n = image.size();
        int m = image[0].size();
        visited[row][col] = true;
        int ocolor = image[row][col];
        image[row][col] = color;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();
            for(int i = -1 ; i <= 1 ; i++) {
                for(int j = -1 ; j <= 1 ; j++) {
                    if(i != j and i != -j) {
                        int nrow = crow + i;
                        int ncol = ccol + j;
                        if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and image[nrow][ncol] == ocolor and !visited[nrow][ncol]) {
                            image[nrow][ncol] = color;
                            visited[nrow][ncol] = true;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bfs(image, visited, sr, sc, newColor);
        return image;
        
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends