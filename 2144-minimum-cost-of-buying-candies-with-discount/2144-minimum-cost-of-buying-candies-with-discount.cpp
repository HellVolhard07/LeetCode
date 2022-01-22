class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        int n = cost.size();
        if(n < 3) {
            if(n == 1) {
                return cost[0];
            }
            else {
                return cost[0] + cost[1];
            }
        }
        sort(cost.begin(), cost.end());
        for(int i = n - 1 ; i >= 0 ; i = i - 3) {
            if(i > 1) {
                int first = cost[i];
                int second = cost[i - 1];
                ans += first + second;
            }
            else {
                if(i == 0) {
                    ans += cost[0];
                }
                else {
                    ans += cost[0] + cost[1];
                }
            }
        }
        return ans;
    }
};