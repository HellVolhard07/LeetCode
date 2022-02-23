/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    unordered_map<Node*, Node*> visited;
    
    Node* dfs(Node* node) {
        if(!node) {
            return NULL;
        }
        if(visited[node]) {
            return visited[node];
        }
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for(auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }
        return clone;
    }
    
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};