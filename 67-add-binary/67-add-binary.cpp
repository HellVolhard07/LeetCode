class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        if(a.length() < b.length()) {
            a.swap(b);
        }
        int m = a.length() - 1;
        int n = b.length() - 1;
        int carry = 0;
        for(int i = 0 ; i <= n ; i++) {
            int sum = (a[m - i] - '0') + (b[n - i] - '0') + carry;
            carry = sum / 2;
            int bit = sum % 2;
            ans += (bit + '0');
        }
        if(carry == 0) {
            if(m == n) {
                reverse(ans.begin(), ans.end());
                return ans;
            }
            else {
                string remainingString = a.substr(0, m - n);
                reverse(remainingString.begin(), remainingString.end());
                ans.append(remainingString);
                reverse(ans.begin(), ans.end());
                return ans;
            }
        }
        else {
            if(m == n) {
                ans.append("1");
                reverse(ans.begin(), ans.end());
                return ans;
            }
            else {
                string remainingString = a.substr(0, m - n);
                remainingString = addBinary(remainingString, "1");
                reverse(remainingString.begin(), remainingString.end());
                ans.append(remainingString);
                reverse(ans.begin(), ans.end());
                return ans;
            }
        }
    }
};