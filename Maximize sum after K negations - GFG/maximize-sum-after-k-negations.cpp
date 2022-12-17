//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        sort(arr,arr+n);
        for(int i =0 ; i<n; i++){
            if(arr[i]<0 && k>0){
                arr[i]=(-arr[i]);
                k--;
            }
            else {
                // cout<<k;
                break;
            }
        }
        
        sort(arr,arr+n);
       if(k>0){
           if(k%2!=0) arr[0]*=-1;
       }
    //   for(int i =0 ; i<n ; i++){
    //       cout<<arr[i]<< " ";
    //   }
    //   cout<<endl;
        long long int sum=0;
        return accumulate(arr, arr+n, sum);
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends