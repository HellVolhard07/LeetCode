class Solution {
public:
    
    void reverse(vector<int> &nums, int start, int end) {
        while(start < end) {
            swap(nums[start++], nums[end--]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 or k == 0) {
            return;
        }
        if(k > n) {
            k = k % n;
        }
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};