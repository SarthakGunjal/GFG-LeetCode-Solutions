//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    #define vi vector<int>
    #define vvi vector<vi>
    const int MOD = 1e9+7;
    
    vvi mul(vvi& mat1, vvi& mat2) {
        int r1 = mat1.size(), c1 = mat1[0].size();
        int r2 = mat2.size(), c2 = mat2[0].size();
        
        if(c1 != r2) return {};
        
        vvi res(r1, vi(c2));
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++) {
                long long val = 0;
                for(int k = 0; k < c1; k++) {
                    val += ((long long)mat1[i][k]) * mat2[k][j];
                    val %= MOD;
                }
                res[i][j] = val;
            }
        }
        
        return res;
    }
    
    vvi power(vvi& mat, long long n) {
        int r = mat.size();
        vvi res(r, vi(r));
        for(int i = 0; i < r; i++)
            res[i][i] = 1;
        
        while(n) {
            if(n & 1) 
                res = mul(res, mat);
            mat = mul(mat, mat);
            n >>= 1;
        }
        return res;
    }
    
    int fib(long long n) {
        vvi mat = {{0,1},
                   {1,1}};
        vvi base = {{0},
                    {1}};
        
        mat = power(mat, n);
        vvi res = mul(mat, base);
        return res[0][0];
    }
      
    int countStrings(long long int n) {
        return fib(n+2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends