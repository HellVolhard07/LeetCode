class Solution {
public:
    int binsearch(vector<int> &A, int key) {
        int l = 0;
        int r = A.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(A[mid] == key) {
                return mid;
            }
            else if(A[mid] > key) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    return -1;
}
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i, j;
        for(i = 0 ; i < n ; i++) {
            int one = numbers[i];
            int two = target - one;
            j = binsearch(numbers, two);
            if(j != -1 and i != j) {
                break;
            }
        }
        if(i < j) {
            return {i + 1, j + 1};
        }
        else {
            return {j + 1, i + 1};
        }
    }
};