//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {

        vector<int>ans;

        int rowNumber;

        int finalCount=INT_MIN;

        int m=mat.size();

        int n=mat[0].size();

        for(int i=0;i<m;i++){

            int maxCount=0;

            for(int j=0;j<n;j++){

                if(mat[i][n-1]==0){

                    maxCount=0;

                    break;

                }

                else if(mat[i][j]==1){

                    maxCount=n-j;

                    break;

                }

            }

            if(maxCount>finalCount){

                rowNumber=i;

                finalCount=maxCount;

            }

        }

        ans.push_back(rowNumber);

        ans.push_back(finalCount);

        

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends