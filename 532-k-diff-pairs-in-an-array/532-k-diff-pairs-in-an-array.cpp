class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num : nums) {
            freq[num]++;
        }
        int ans = 0;
        for(auto x : freq) {
            if(k == 0) {
                if(x.second > 1) {
                    ans++;
                }
            }
            else if(freq.count(x.first + k) > 0) {
                ans++;
            }
        }
        return ans;
    }
};