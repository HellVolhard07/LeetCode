// MOORE'S VOTING ALGORITHM
// Time: O(n), Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int ans;
        for(int num : nums) {
            if(counter == 0) {
                ans = num;
            }
            counter += num == ans ? 1 : -1;
            // if(num == ans) {
            //     counter++;
            // }
            // else {
            //     counter--;
            // }
        }
        return ans;
    }
};

/*
Time: O(n), Space: O(n)
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int ans = 0;
        for(int num : nums) {
            freq[num]++;
        }
        
        for(auto i : freq) {
            if(i.second > (n / 2)) {
                ans = i.first;
            }
        }
        return ans;
    }

*/