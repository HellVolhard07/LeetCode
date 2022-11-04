class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // List as 1: {{0, 0}, {0, 0}}
        vector<pair<double, int>> adj[n];
        for(int i = 0 ; i < edges.size() ; i++) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            adj[v1].push_back({succProb[i], v2});
            adj[v2].push_back({succProb[i], v1});
        }
        vector<double> ans(n, (double)0.0);
        // Prob, vertex
        priority_queue<pair<double, int>> pq;
        pq.push({double(1.0), start});
        ans[start] = 1.0;
        while(!pq.empty()) {
            int parent = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for(auto i : adj[parent]) {
                int node = i.second;
                double probability = i.first;
                if(ans[node] < prob * probability) {
                    ans[node] = prob * probability;
                    pq.push({ans[node], node});
                }
            }
        }
        return ans[end];
    }
};