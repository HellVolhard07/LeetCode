//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
bool compare(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

class Solution{
public:
	
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), compare);
	    string ans;
	    for(int i = 0 ; i < arr.size() ; i++) {
	        ans += arr[i];
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends