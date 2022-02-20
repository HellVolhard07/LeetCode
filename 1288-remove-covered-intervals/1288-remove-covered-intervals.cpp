class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int n = intervals.size();
        int min = intervals[0][0];
        int max = intervals[0][1];
        for(int i = 1 ; i < n ; i++) {
            if(intervals[i][0] >= min and intervals[i][1] <= max) {
                ans++;
            }
            if(intervals[i][1] > max) {
                if(min == intervals[i][0]) {
                    ans++;
                }
                min = intervals[i][0];
                max = intervals[i][1];
            }
        }
        
        return (n - ans);
    }
};



/*

[a, b] = [2, 5]
[c, d] = [1, 8], [2, 5]

[[1,4],[2,8],[3,6]]

*/