class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max heap
        priority_queue<int, vector<int>, greater<int>> numbers;;
        for(int i = 0 ; i < nums.size() ; i++) {
            numbers.push(nums[i]);
            // keeping greatest k elements so far in heap
            if(numbers.size() > k) {
                numbers.pop();
            }
        }
        return numbers.top();
    }
};