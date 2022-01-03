int dfs(int l, int r, vector<int>& nums, vector<vector<int>> &dp) {
    if(l > r) {
        return 0;
    }
    if(dp[l][r] != -1) {
        return dp[l][r];
    }
    dp[l][r] = 0;
    for(int i = l ; i <= r ; i++) {
        int coins = nums[l - 1] * nums[i] * nums[r + 1];
        coins += (dfs(l, i - 1, nums, dp) + dfs(i + 1, r, nums, dp));
        dp[l][r] = max(dp[l][r], coins);
    }
    return dp[l][r];
}

class Solution {
public:
    int maxCoins(vector<int> nums) {
        vector<vector<int>> dp(nums.size() + 2, vector<int> (nums.size() + 2, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return dfs(1, (int)nums.size() - 2, nums, dp);
    }
};
