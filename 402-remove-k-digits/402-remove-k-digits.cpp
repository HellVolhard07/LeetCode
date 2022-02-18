class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> peak;
        for(char ch : num) {
            while(!peak.empty() and ch < peak.top() and k) {
                peak.pop();
                k--;
            }
            if(!peak.empty() or ch != '0') {
                peak.push(ch);
            }
        }
        while(!peak.empty() and k) {
            peak.pop();
            if(peak.empty()) {
                return "0";
            }
            k--;
        }
        if(peak.empty()) {
            return "0";
        }
        while(!peak.empty()) {
            ans += peak.top();
            peak.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};