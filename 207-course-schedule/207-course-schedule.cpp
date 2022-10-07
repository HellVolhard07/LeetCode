class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> indegree(n, 0);
        vector<int> adj[n];
        queue<int> q;
        for(auto x : p) {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()) {
            count++;
            int node = q.front();
            q.pop();
            for(int i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        return count == n;
    }
};