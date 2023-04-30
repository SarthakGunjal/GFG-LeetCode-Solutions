//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        vector<pair<int,int>>v;
       for(int i=0;i<n;i++){
           v.push_back({intervals[i][0],1});
           v.push_back({intervals[i][1]+1,-1});
       }
       sort(v.begin(),v.end());
       int sum=0,ans=-1;;
       for(auto i:v){
           if(sum>=k)ans=i.first-1;
           sum+=i.second;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends