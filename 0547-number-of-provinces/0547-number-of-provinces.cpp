class Solution {
public:
    
    void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for(int i : adj[node]) {
            if(!visited[i]) dfs(i, adj, visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i = 0 ; i <  n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(isConnected[i][j] and i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 0 ; i <  n ; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                ans++;
            }
        }
        return ans;
    }
};