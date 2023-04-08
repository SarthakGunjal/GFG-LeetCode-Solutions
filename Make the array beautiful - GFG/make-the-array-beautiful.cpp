//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> v;
        stack<int> stk;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if (!stk.empty()){
                if ((arr[i]>=0 and stk.top()<0) or (arr[i]<0 and stk.top()>=0)){
                    stk.pop();
                }
                else stk.push(arr[i]);
            }
            else stk.push(arr[i]);
        }
        while (!stk.empty()) {
        v.push_back(stk.top());
        stk.pop();
    }
        reverse(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends