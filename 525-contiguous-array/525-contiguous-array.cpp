class Solution {   
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> min_index;
        int n = nums.size();
        int prefixSum = 0;
        int ans = 0;
        min_index[0] = -1;
        for(int i = 0 ; i < n ; i++) {
            prefixSum += (nums[i] == 0) ? -1 : 1;
            if(min_index.count(prefixSum)) {
                ans = max(ans, i - min_index[prefixSum]);
            }
            else {
                min_index[prefixSum] = i;
            }
        }
        return ans;
    }
};