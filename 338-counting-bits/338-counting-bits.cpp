class Solution {
    int count(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return (n % 2 == 0 ? count(n / 2) : 1 + count(n / 2));
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans (n + 1);
        for(int i = 0 ; i <= n ; i++) {
            ans[i] = (count(i));
        }
        return ans;
    }
};