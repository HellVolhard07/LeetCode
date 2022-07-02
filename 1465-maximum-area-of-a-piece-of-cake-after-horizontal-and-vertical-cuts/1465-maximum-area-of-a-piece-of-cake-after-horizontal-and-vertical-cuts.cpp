class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxh = horizontalCuts[0];
        int maxv = verticalCuts[0];
        for(int i = 0 ; i < horizontalCuts.size() - 1 ; i++) {
            maxh = max(maxh, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for(int i = 0 ; i < verticalCuts.size() - 1 ; i++) {
            maxv = max(maxv, verticalCuts[i + 1] - verticalCuts[i]);
        }
        return (1LL*maxh*maxv) % 1000000007;
    }
};