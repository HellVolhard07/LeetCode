class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] < 0) swap(min_so_far, max_so_far);
            max_so_far = max(nums[i], max_so_far * nums[i]);
            min_so_far = min(nums[i], min_so_far * nums[i]);
            ans = max(ans, max_so_far);
        }
        return ans;
    }
};