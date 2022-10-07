class Solution {
public:
    
    bool bfs(int i, vector<int> &color, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i : graph[node]) {
                if(color[i] == -1) {
                    color[i] = 1 - color[node];
                    q.push(i);
                }
                else if(color[i] == 1 - color[node]) continue;
                else return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0 ; i < graph.size() ; i++) {
            if(color[i] == -1) {
                if(!bfs(i, color, graph)) return false;
            }
        }
        return true;
    }
};