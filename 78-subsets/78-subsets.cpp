class Solution {
    
    void getSubset(vector<int> &nums, int index, vector<int> temp) {
        if(index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        getSubset(nums, index + 1, temp);
        temp.push_back(nums[index]);
        getSubset(nums, index + 1, temp);
    }
    
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        getSubset(nums, 0, temp);
        return ans;
    }
};