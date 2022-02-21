class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int ans = 0;
        for(int num : nums) {
            freq[num]++;
        }
        
        for(auto i : freq) {
            if(i.second > (n / 2)) {
                ans = i.first;
            }
        }
        return ans;
    }
};