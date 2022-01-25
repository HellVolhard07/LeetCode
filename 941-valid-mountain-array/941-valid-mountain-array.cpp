class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) {
            return false;
        }
        int i = 0;
        int increasing = 0;
        int decreasing = 0;
        while(arr[i] < arr[i + 1]) {
            increasing = 1;
            i++;
        }
        while(i < arr.size() - 1 and arr[i] > arr[i + 1]){
            decreasing = 1;
            i++;
        }
        return (i + 1 == arr.size() and increasing and decreasing);
    }
};