class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = 1 << nums.size();
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i++) {
            int mask = i;
            vector<int> temp;
            for(int j = 0 ; j < nums.size() ; j++) {
                if((mask & 1) == 1) {
                    temp.push_back(nums[j]);
                }
                mask >>= 1;
            }
            sort(temp.begin(), temp.end());
            s.insert(temp);
        }
        vector<vector<int>> ans;
        for(auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};