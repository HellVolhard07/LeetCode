class Solution {
public:
    int dp[31] = {0};
    int fib(int n) {
        if(n == 0 or n == 1) {
            return n;
        }
        else {
            dp[n] = fib(n - 1) + fib(n - 2);
            return dp[n];
        }
    }
};