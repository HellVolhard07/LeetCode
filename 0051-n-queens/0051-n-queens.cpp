class Solution {
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &left, vector<int> &top_left, vector<int> &bottom_left, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row < n ; row++) {
            if(left[row] == 0 and top_left[n - 1 + col - row] == 0 and bottom_left[row + col] == 0) {
                board[row][col] = 'Q';
                left[row] = 1;
                top_left[n - 1 + col - row] = 1;
                bottom_left[row + col] = 1;
                solve(col + 1, board, ans, left, top_left, bottom_left, n);
                left[row] = 0;
                top_left[n - 1 + col - row] = 0;
                bottom_left[row + col] = 0;
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0 ; i < n ; i++) {
            board[i] = s;
        }
        vector<int> left(n, 0);
        vector<int> top_left(2 * n - 1, 0);
        vector<int> bottom_left(2 * n - 1, 0);
        solve(0, board, ans,left, top_left, bottom_left, n);
        return ans;
    }
};