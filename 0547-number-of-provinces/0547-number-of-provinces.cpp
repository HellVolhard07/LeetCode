class Solution {
public:
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
        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(!visited[i]) {
                q.push(i);
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(int i : adj[node]) {
                        if(!visited[i]) {
                            visited[i] = true;
                            q.push(i);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};