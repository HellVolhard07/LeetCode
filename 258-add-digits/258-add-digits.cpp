class Solution {
public:
    int addDigits(int num) {
        int temp;
        int ans = num;
        while(ans > 9) {
            int new_answer = 0;
            temp = ans;
            while(temp) {
                new_answer += temp % 10;
                temp /= 10;
            }
            ans = new_answer;
        }
        return ans;
    }
};