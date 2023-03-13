//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
     long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
    long long ans = 0;

    int count = 0;

    int mini = INT_MAX;

    for(int i= 0;i<A.size();i++){

    if(B[i]/2>0){

        ans += 2*(B[i]/2)*A[i];

        count = count + (B[i]/2) ;

       mini = min(mini,A[i]); 

    }

    }

    if(count%2 == 1){

    ans = ans - 2*mini ;

    }

   

    return ans ;

        // code here

    }
 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends