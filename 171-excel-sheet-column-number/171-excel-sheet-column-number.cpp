class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int n = columnTitle.length();
        for(int i = 0 ; i < n ; i++) {
            int digit = columnTitle[i] - 'A' + 1;
            ans = 26 * ans + digit;
        }
        return ans;
    }
};