class Solution {
public:
    int findRotation(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(r > l + 1) {
            int mid = (l + r) / 2;
            if(nums[mid] > nums[r]) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if(nums[l] > nums[r]) {
            return r;
        }
        else {
            return 0;
        }
    }
    
    int find(vector<int> &nums, int target, int left, int right) {
        int l = left - 1;
        int r = right + 1;
        while(r > l + 1) {
            int mid = (l + r) / 2;
            if(nums[mid] < target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if(r < nums.size() and nums[r] == target) {
            return r;
        }
        else {
            return -1;
        }
    }
    
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int i = findRotation(nums);
        if(i != 0) {
            int ans = find(nums, target, 0, i - 1);
            if(ans == -1) {
                ans = find(nums, target, i, r);;
            }
            return ans;
        }
        else {
            return find(nums, target, 0, r);
        }
    }
};