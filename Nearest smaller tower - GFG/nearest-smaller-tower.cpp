//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     vector<int> nearestSmallerTower(vector<int> arr) {
    	// code here
    	int n = arr.size();
    	vector<int> left(n);
    	stack<int> st;
    
    	for (int i = 0; i < n; i++) {
    		int curr = arr[i];
    		while (st.empty() == false && arr[st.top()] >= curr) {
    			st.pop();
    		}
    		left[i] = st.empty() ? -1 : st.top();
    		st.push(i);
    	}
    
    	while (st.empty() == false) st.pop();
    
    	vector<int> right(n, -1);
    	for (int i = 0; i < n; i++) {
    		int curr = arr[i];
    		while (st.empty() == false && arr[st.top()] > curr) {
    			right[st.top()] = i;
    			st.pop();
    		}
    		st.push(i);
    	}
        
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            int lIdx = left[i];
            int rIdx = right[i];
            if(lIdx == -1 || rIdx == -1) {
                res[i] = max(lIdx, rIdx);
            } else if(i - lIdx == rIdx - i) {
                res[i] = (arr[lIdx] <= arr[rIdx]) ? lIdx : rIdx;
            } else {
                res[i] = (i - lIdx < rIdx - i) ? lIdx : rIdx;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends