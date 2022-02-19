class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num % 3 != 0) {
            return {};
        }
        else {
            long long mid = num / 3;
            ans.push_back(mid - 1);
            ans.push_back(mid);
            ans.push_back(mid + 1);
        }
        return ans;
    }
};