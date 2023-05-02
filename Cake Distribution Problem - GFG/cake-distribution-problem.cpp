//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool ispossible(vector<int> &sw,int k,long long mid)
    {
        int count = 0;
        long long sum=0;
        for(auto &it:sw)
        {
            sum+=it;
            if(sum>=mid){
                count++;
                sum=0;
            }
        }
        return count>=k+1;
    }
    int maxSweetness(vector<int>& sw, int n, int k) {
        long long high = 0;
        long long low = sw[0];
        for(auto &it:sw) 
        {
            high+=it;
            low = min(low,(long long)it);
        }
        long long mid = 0;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(ispossible(sw,k,mid)) low = mid+1;
            else high = mid-1;
        }
        return low-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends