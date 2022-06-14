class Solution {
public:
    int lcs(vector<vector<int>> &dp, string word1, string word2, int m, int n) {
        if(m == 0 or n == 0) {
            return 0;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        if(word1[m - 1] == word2[n - 1]) {
            return dp[m][n] = 1 + lcs(dp, word1, word2, m - 1, n - 1);
        }
        else {
            return dp[m][n] = max(lcs(dp, word1, word2, m - 1, n), lcs(dp, word1, word2, m, n - 1));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        int common = lcs(dp, word1, word2, m, n);
        return ((m + n) - (2 * common));
    }
};