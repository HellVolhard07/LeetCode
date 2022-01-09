class Solution {
public:
    int count[46] = {0};
    int climbStairs(int n) {
        if(n == 0 or n == 1 or n == 2) {
            return n;
        }
        if(count[n] == 0) {
            return count[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return count[n];
    }
};