//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    void helper(vector<int> &arr, vector<int> &ans, int index, int n, int sum) {
        if(index == n) {
            ans.push_back(sum);
            return;
        }
        helper(arr, ans, index + 1, n, sum);
        helper(arr, ans, index + 1, n, sum + arr[index]);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum = 0;
        vector<int> ans;
        helper(arr, ans, 0, N, sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends