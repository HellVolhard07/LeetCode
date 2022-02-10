class Solution {
    vector<int> getPrefixSum(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        return prefix;
    }
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix = getPrefixSum(nums);
        unordered_map<int, int> freq;
        int ans = 0;
        for(int i : prefix) {
            if(i == k) {
                ans++;
            }
            if(freq.count(i - k)) {
                ans += freq[i - k];
            }
            freq[i]++;
        }
        return ans;
    }
};