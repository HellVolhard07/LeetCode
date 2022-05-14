class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m, 1);
        vector<int> cols(n, 1);
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        for(int i = 0 ; i < m ; i++) {
            if(rows[i] == 0) {
                for(int j = 0 ; j < n ; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            if(cols[i] == 0) {
                for(int j = 0 ; j < m ; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};