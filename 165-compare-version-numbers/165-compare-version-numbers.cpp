class Solution {
    /*
    12345
    1
    10+2
    120+3
    
    */
    vector<int> stringToArr(string s) {
        vector<int> arr;
        int n = s.length();
        long long number = 0;
        int index = 0;
        while(index < n) {
            if(s[index] == '.') {
                arr.push_back(number);
                number = 0;
            }
            else {
                number = (number * 10) + (s[index] - '0');
            }
            index++;
        }
        arr.push_back(number);
        return arr;
    }
    
public:
    int compareVersion(string version1, string version2) {
        vector<int> arr1 = stringToArr(version1);
        vector<int> arr2 = stringToArr(version2);
        for(int i : arr1) {
            cout<<i<<endl;
        }
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = min(n1, n2);
        for(int i = 0 ; i < n ; i++) {
            if(arr1[i] < arr2[i]) {
                return -1;
            }
            if(arr1[i] > arr2[i]) {
                return 1;
            }
        }
        for(int i = n ; i < n1 ; i++) {
            if(arr1[i] != 0) {
                return 1;
            }
        }
        for(int i = n ; i < n2 ; i++) {
            if(arr2[i] != 0) {
                return -1;
            }
        }
        return 0;
    }
};