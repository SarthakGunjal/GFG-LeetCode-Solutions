//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

        bool check(int x,vector<int>&s,int k){

        int lst = s[0];

        int cnt = 1 ;

        for(int i=1;i<s.size();i++){

            if(s[i]-lst>=x) {

                cnt++;

                lst = s[i];

            }

        }

        return cnt>=k;

    }

    int solve(int n, int k, vector<int> &s) {

    

        

        sort(s.begin(),s.end());

        int l = 0,r = 1000000000;

        if(check(r,s,k)) return r;

        while(r>l+1){

            int m = (l+r)/2;

            if(check(m,s,k)) l=m;

            else r=m;

        }

        return l;

        

    }

};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends