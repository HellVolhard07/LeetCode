class Solution {
    /*
    
    456
     77
    
    */
public:
    string addStrings(string nums1, string nums2) {
        if(nums1.length() < nums2.length()) {
            nums1.swap(nums2);
        }
        string ans;
        int p1 = nums1.length() - 1;
        int p2 = nums2.length() - 1;
        int carry = 0;
        int sum = 0;
        while(p2 >= 0) {
            sum = (nums1[p1] - '0') + (nums2[p2] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans += sum + '0';
            p1--;
            p2--;
        }
        while(p1 >= 0) {
            sum = (nums1[p1] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans += sum + '0';
            p1--;
        }
        if(carry) {
            ans += carry + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};