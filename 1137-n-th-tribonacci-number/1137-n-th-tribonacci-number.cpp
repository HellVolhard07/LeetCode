class Solution {
public:
    int dp[38];
    int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n == 1 or n == 2) {
            return 1;
        }
        if(dp[n] == 0) {
            dp[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        }
        return dp[n];
    }
};