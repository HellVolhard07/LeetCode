class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &rooms, vector<bool> &visited) {
        visited[i] = true;
        for(int key : rooms[i]) {
            if(!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        for(bool i : visited){
            if(!i) {
                return false;
            }
        }
        return true;
    }
};