class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        for(int i : s) {
            ch ^= i;
        }
        for(int i : t) {
            ch ^= i;
        }
        return ch;
    }
};