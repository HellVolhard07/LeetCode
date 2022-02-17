class Solution {
    
    vector<int> temp;
    
    void getCombinations(vector<vector<int>> &ans, vector<int> &candidates, int target, int index) {
        if(target < 0) {
            return;
        }        
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(index == 0) {
            return;
        }
        if(candidates[index - 1] <= target) {
            temp.push_back(candidates[index - 1]);
            getCombinations(ans, candidates, target - candidates[index - 1], index);
            temp.pop_back();
            getCombinations(ans, candidates, target, index - 1);
        }
        else {
            getCombinations(ans, candidates, target, index - 1);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        getCombinations(ans, candidates, target, n);
        return ans;
    }
};