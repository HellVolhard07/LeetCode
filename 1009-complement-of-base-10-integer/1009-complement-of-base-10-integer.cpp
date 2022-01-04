class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }
        int power = 0;
        while(pow(2, power) - 1 < n) {
            power++;
        }
        return (pow(2, power) - 1 - n);
    }
};