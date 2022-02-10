class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int left = 0;
        int right = m;
        while(left <= right) {
            // division by 2
            int mid_nums1 = (left + right) >> 1;
            // since this is number of elements
            int mid_nums2 = ((total + 1) / 2) - mid_nums1;
            
            int nums1_left = mid_nums1 > 0 ? nums1[mid_nums1 - 1] : INT_MIN;
            int nums1_right = mid_nums1 < m ? nums1[mid_nums1] : INT_MAX;
            int nums2_left = mid_nums2 > 0 ? nums2[mid_nums2 - 1] : INT_MIN;
            int nums2_right = mid_nums2 < n ? nums2[mid_nums2] : INT_MAX;
            
            // correct partition
            if(nums1_left <= nums2_right and nums2_left <= nums1_right) {
                // odd
                if(total % 2) {
                    return max(nums1_left, nums2_left);
                }
                // even
                else {
                    return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2.0;
                }
            }
            else if (nums1_left > nums2_right) {
                right = mid_nums1 - 1;
            }
            else {
                left = mid_nums1 + 1;
            }
        }
        return 0.0;
    }
};