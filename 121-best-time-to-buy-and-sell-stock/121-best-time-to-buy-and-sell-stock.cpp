class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX;
        int maxSoFar = 0;
        for(int i = 0; i < prices.size() ; i++) {
            if(prices[i] < minSoFar) {
                minSoFar = prices[i];
            }
            else {
                maxSoFar = max(maxSoFar, (prices[i] - minSoFar));
            }
        }
        return maxSoFar;
    }
};