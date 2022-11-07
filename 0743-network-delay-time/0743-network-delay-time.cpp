class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // List as parent: [{time, child}]
        vector<pair<int, int>> adj[n];
        for(int i = 0 ; i < times.size() ; i++) {
            int parent = times[i][0] - 1;
            int child = times[i][1] - 1;
            int time = times[i][2];
            adj[parent].push_back({time, child});
        }
        // Travel time for each node
        vector<int> tt(n, INT_MAX);
        int ans = 0;
        // Min Heap as {time, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        tt[k - 1] = 0;
        pq.push({0, k - 1});
        while(!pq.empty()) {
            int parent = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            for(auto i : adj[parent]) {
                int node = i.second;
                int time = i.first;
                if(tt[node] > t + time) {
                    tt[node] = t + time;
                    pq.push({tt[node], node});
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            if(tt[i] == INT_MAX) return -1;
            ans = max(ans, tt[i]);
        }
        return ans;
    }
};