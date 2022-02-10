class Solution {
    
    bool noRepeating(unordered_map<char, int> &freq) {
        for(auto i : freq) {
            if(i.second > 1) {
                return false;
            }
        }
        return true;
    }
    
    int getSize(unordered_map<char, int> &freq) {
        int size = 0;
        for(auto i : freq) {
            if(i.second != 0) {
                size++;
            }
        }
        return size;
    }
    /*
    a b c
    3
    */
    
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n < 2) {
            return n;
        }
        unordered_map<char, int> freq;
        int ans = 0;
        int start = 0;
        int end = 1;
        freq[s[start]]++;
        freq[s[end]]++;
        while(end < n - 1) {
            if(noRepeating(freq)) {
                int size = getSize(freq);
                ans = max(ans, size);
                end++;
                freq[s[end]]++;
            }
            else {
                freq[s[start]]--;
                start++;
                end++;
                freq[s[end]]++;
                // int size = getSize(freq);
                // ans = max(ans, size);
            }
        }
        int size = getSize(freq);
        ans = max(ans, size);
        return ans;
    }
};