//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        // Code here
        map<int,int> mp;
        for (int i=0; i<n; i++){
            mp[frogs[i]]++;
        }
        
        int ans=0;
        
        for (int i=1; i<=leaves; i++){
            bool flag=false;
            
            for (int j=1; j*j<=i; j++){
                
                if ((i%j)==0){
                    if (mp[j]){
                        flag=true;
                        break;
                    }
                    else if (j!=(i/j)){
                        if (mp[(i/j)]){
                            flag=true;
                            break;
                        }
                    }
                }
            }
            
            
            if (!flag){
                ans++;
            }
        }
        
     return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends