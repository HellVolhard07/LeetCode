class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(mp.count(target - nums[i]) and mp[target - nums[i]] != i) {
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};