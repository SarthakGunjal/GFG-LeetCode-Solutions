//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int f(int k,int l , int h,vector<int>&v)
    {
    
        int res=-1;
        while(h>=l)
        {
            int m=l+(h-l)/2;
            if(v[m]<k)
            {
                h=m-1;
            }
            else
            {
                res=m;
                l=m+1;
            }
        }
    }
    int dominantPairs(int n,vector<int> &arr){
        // Code here
       
        
         sort(arr.begin(),arr.begin()+n/2,greater<int>());
         
        int ans=0;
        for(int i=n/2;i<n;i++)
        {
            int x=f(5*arr[i],0,n/2-1,arr);
            
            ans=ans+x+1;
            
        }
        return ans;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends