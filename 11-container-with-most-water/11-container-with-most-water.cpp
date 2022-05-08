class Solution {
public:
    int maxArea(vector<int>& h) {
        int w = h.size() - 1;
        int start = 0;
        int end = w;
        int ans = INT_MIN;
        while(start < end) {
            int minh = min(h[start], h[end]);
            int area = w * minh;
            ans = max(ans, area);
            if(h[start] <= h[end]) {
                start++;
                w--;
            }
            else {
                end--;
                w--;
            }
        }
        return ans;
    }
};