class Solution {
public:
    
    int helper(vector<int> &nums, vector<int> &dp, int i) {
        if(i < 0) return 0;
        if(i == 0) return nums[i];
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + helper(nums, dp, i - 2), helper(nums, dp, i - 1));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(nums, dp, n - 1);
    }
};