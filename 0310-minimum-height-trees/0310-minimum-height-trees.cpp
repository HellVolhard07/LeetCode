class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> adj[n];
        vector<int> degree(n, 0);
        for(int i = 0 ; i < edges.size() ; i++) {
            
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(degree[i] == 1) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int n = q.size();
            ans.clear();
            while(n--) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(int i : adj[node]) {
                    degree[i]--;
                    if(degree[i] == 1) q.push(i);
                }
            }
        }
        return ans;
    }
};