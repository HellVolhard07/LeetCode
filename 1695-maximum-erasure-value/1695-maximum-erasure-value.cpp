class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> freq;
        int start = 0;
        int end = 0;
        int sumSoFar = 0;
        int maxSum = 0;
        while(end < n) {
            while(freq.count(nums[end])) {
                freq.erase(nums[start]);
                sumSoFar -= nums[start];
                start++;
            }
            sumSoFar += nums[end];
            freq.insert(nums[end]);
            end++;
            maxSum = max(maxSum, sumSoFar);
        }
        return maxSum;
    }
};