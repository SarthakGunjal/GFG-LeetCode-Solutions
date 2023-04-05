//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
       int mx=*max_element(arr.begin(),arr.end());
       int ans=0;
       vector<int> seive(mx+1,0);
       for(int i=0;i<N;i++){
           if(seive[arr[i]]<=1){
               for(int j=arr[i];j<=mx;j+=arr[i]) seive[j]++;
           }
       }
       for(int i=0;i<N;i++){
           if(seive[arr[i]]>1) ans++;
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends