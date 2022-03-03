class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first = 0;
        int second = 0;
        while(first < s.length() and second < t.length()) {
            if(s[first] == t[second]) {
                first++;
                second++;
            }
            else {
                second++;
            }
        }
        if(first == s.length()) {
            return true;
        }
        return false;
    }
};