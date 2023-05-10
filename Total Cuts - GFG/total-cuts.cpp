//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        
        int ans=0;
        int smallest = INT_MAX;
        vector<int>small;
        for(int i=N-1;i>=0;i--)
        {
            smallest = min(smallest,A[i]);
            small.push_back(smallest);
        }
        reverse(small.begin(),small.end());
        int largest = INT_MIN;
        for(int i=1;i<N;i++)
        {
            if(A[i-1]>largest)
            {
                largest=A[i-1];
                
            }
            if(largest+small[i]>=K)
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends