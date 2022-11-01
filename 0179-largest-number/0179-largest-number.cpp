bool compare(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> container;
        for(int i : nums) {
            container.push_back(to_string(i));
        }
        sort(container.begin(), container.end(), compare);
        string ans;
        for(string num : container) {
            ans += num;
        }
        return ans[0] == '0' ? "0" : ans;
    }
};