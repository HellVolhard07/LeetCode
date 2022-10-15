//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(vector<int> adj[], vector<bool> &visited, int node) {
        visited[node] = true;
        for(int i : adj[node]) {
            if(!visited[i]) dfs(adj, visited, i);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adjm, int V) {
        vector<int> adj[V];
        for(int i = 0 ; i < V ; i++) {
            for(int j = 0 ; j < V ; j++) {
                if(adjm[i][j] == 1 and i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V, false);
        int ans = 0;
        for(int i = 0 ; i < V ; i++) {
            if(!visited[i]) {
                ans++;
                dfs(adj, visited, i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends