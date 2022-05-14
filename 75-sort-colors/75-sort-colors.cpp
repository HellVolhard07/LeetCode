class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int i = 0;
        while(start < end and i <= end) {
            if(nums[i] == 0) {
                swap(nums[start], nums[i]);
                start++;
                i++;
            }
            else if(nums[i] == 2) {
                swap(nums[end], nums[i]);
                end--;
            }
            else {
                i++;
            }
        }
    }
};