class Solution {
public:
    static bool compare(vector<int> first, vector<int> second) {
        return (first[1] > second[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        int i = 0;
        while(truckSize and i < boxTypes.size()) {
            if(truckSize >= boxTypes[i][0]) {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else {
                ans += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            i++;
        }
        return ans;
    }
};