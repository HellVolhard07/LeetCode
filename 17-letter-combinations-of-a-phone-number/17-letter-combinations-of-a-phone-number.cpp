class Solution {
    unordered_map<char, string> combinations = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
}; 

public:
    
    void helper(string digits, vector<string> &ans) {
        
        if(digits.length() == 0) {
            ans.push_back("");
            return;
        }
        
        helper(digits.substr(1), ans);
        int copies = combinations[digits[0]].length() - 1;
        int groupSize = ans.size();
        for(int i = 0 ; i < copies ; i++) {
            for(int j = 0 ; j < groupSize ; j++) {
                ans.push_back(ans[j]);
            }
        }
        int k = 0;
        for(int i = 0 ; i <= copies ; i++) {
            for(int j = 0 ; j < groupSize ; j++) {
                ans[k] = combinations[digits[0]][i] + ans[k];
                k++;
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) {
            return {};
        }
        vector<string> ans;
        helper(digits, ans);
        return ans;
    }
};