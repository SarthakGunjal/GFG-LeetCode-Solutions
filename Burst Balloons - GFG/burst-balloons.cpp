//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
      int maxcoin(auto &dp, int l, int r, const auto &nums)

    {

        if(r - l == 1) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for(int i = l + 1; i < r; ++i)

        {

            ans = max(ans, nums[l] * nums[i] * nums[r] + maxcoin(dp, l, i, nums ) + maxcoin(dp, i, r, nums));

        }

        dp[l][r] = ans;

        return ans;

    }

public:

    int maxCoins(int N, vector<int> &arr) {

        // code here

         arr.insert(arr.begin(), 1);

        arr.push_back(1);

    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

    return maxcoin(dp, 0, arr.size() - 1, arr);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends