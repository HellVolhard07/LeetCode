class Solution {
public:
    long long dfs(vector<vector<long long>> &adj, vector<long long> &visited, long long start, long long &count) {
        visited[start] = 1;
        count++;
        for(auto i : adj[start]) {
            if(!visited[i]) {
                dfs(adj, visited, i, count);
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<long long>> adj(n + 1);
        for(int i = 0 ; i < m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long> visited (n, 0);
        long long ans = 0;
        long long count;
        for(int i = 0 ; i < n ; i++) {
            count = 0;
            if(!visited[i]) {
                count = dfs(adj, visited, i, count);
                ans += (count * (n - count));
            }
        }
        return ans / 2;
    }
};