//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int, int> mp;
        for(int i = 0; i < N; i++)
        {
            int a = lines[i][0], b = lines[i][1];
            mp[a] += 1;
            mp[b+1] -= 1;
        }
        int sum = 0, maxi = 0;
        for(auto it: mp)
        {
            sum += it.second;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends