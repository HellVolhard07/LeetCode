class Solution {
    
    set<int> subStrings;
    
    void getSubStrings(string s) {
        int l = 0;
        int r = s.length();
        for(int i = 0 ; i < r ; i++) {
            for(int j = 1 ; j <= r - i ; j++) {
                subStrings.insert(stoi(s.substr(i, j)));
            }
        }
    }
    
public:
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        getSubStrings(s);
        for(auto itr = subStrings.begin() ; itr != subStrings.end() ; itr++) {
            if(*itr >= low and *itr <= high) {
                ans.push_back(*itr);
            }
        }
        return ans;
    }
};