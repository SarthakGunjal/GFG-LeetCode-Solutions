//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
   bool solve(int ind, int k, int target, vector<int> &coins, vector<vector<int>> &dp) {
       
        if(target == 0 and k == 0) return true;
        
        if(k == 0 or ind < 0) return false;
        
        if(dp[k][target] != -1) return dp[k][target];
        
        bool notTake = solve(ind - 1, k, target, coins, dp);
        
        bool take = false;
        if(coins[ind] <= target) 
            take = solve(ind, k - 1, target - coins[ind], coins, dp);
        
        return dp[k][target] = take or notTake;
    }
  
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        // // TOP DOWN
        // vector<vector<int>> dp(k + 1, vector<int> (target + 1, -1));
        // return solve(n - 1, k, target, coins, dp);
        
        // BOTTOM UP
        vector<vector<int>> dp(k + 1, vector<int> (target + 1, 0));
        dp[0][0] = 1;
        
        for(int ind = 0; ind < n; ind++) {
            for(int i = 1; i <= k; i++) {
                for(int j = 1; j <= target; j++ ) {
                    bool notTake = dp[i][j];
                    
                    bool take = false;
                    if(coins[ind] <= j)
                        take = dp[i - 1][j - coins[ind]];
                        
                    dp[i][j] = take or notTake;
                }
            }
        }
        
        return dp[k][target];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends