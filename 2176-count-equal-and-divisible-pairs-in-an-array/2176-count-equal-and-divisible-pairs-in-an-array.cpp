class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n - 1 ; i++) {
            for(int j = i + 1 ; j < n ; j++) {
                if(nums[i] == nums[j]) {
                    if((i * j) % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};