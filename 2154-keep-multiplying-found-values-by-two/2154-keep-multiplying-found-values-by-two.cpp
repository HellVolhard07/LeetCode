class Solution {
public:
    
    int binarySearch(vector<int> &nums, int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == x) {
                return mid;
            }
            if (nums[mid] > x) {
                return binarySearch(nums, l, mid - 1, x);
            }
            return binarySearch(nums, mid + 1, r, x);
        }
        return -1;
    }
    
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == original) {
                return original * 2;
            }
            else {
                return original;
            }
        }
        sort(nums.begin(), nums.end());
        int left = binarySearch(nums, 0, n, original);
        if(left != -1) {
            while(left != -1 and left < n) {
                left = binarySearch(nums, 0, n - 1, original);
                if(left != -1) {
                    original *= 2;
                }
            }
        }
        return original;
    }
};