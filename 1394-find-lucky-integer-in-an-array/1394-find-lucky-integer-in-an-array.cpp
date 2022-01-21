class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(501);
        for(int i = 0 ; i < n ; i++) {
            count[arr[i]]++;
        }
        for(int i = 500 ; i > 0 ; i--) {
            if(count[i] == i) {
                return i;
            }
        }
        return -1;
    }
};