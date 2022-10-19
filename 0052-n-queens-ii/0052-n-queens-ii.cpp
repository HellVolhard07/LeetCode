class Solution {
    
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int i = row;
        int j = col;
        // top-left
        while(i >= 0 and j >= 0) {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        // left
        i = row;
        j = col;
        while(j >= 0) {
            if(board[i][j] == 'Q') return false;
            j--;
        }
        // bottom-left
        i = row;
        j = col;
        while(i < n and j >= 0) {
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int col, vector<string> &board, int &ans, int n) {
        if(col == n) {
            ans++;
            return;
        }
        for(int row = 0 ; row < n ; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0 ; i < n ; i++) {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};