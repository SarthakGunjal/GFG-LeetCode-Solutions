//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    int kadane(int *a,int n)
    {
        int res = a[0];
        int maxm = a[0];
        for(int i = 1 ; i < n ; i++ )
        {
            maxm = max(maxm+a[i] , a[i]);
            res = max(res,maxm);
        }
        return res;
    }
    
    int circularSubarraySum(int *a, int n)
    {
        int l = kadane(a,n);
        if( l < 0)
            return l;
        int sum = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            sum += a[i];
            a[i] = -a[i];
        }
        int c = sum + kadane(a,n);
        int res = max(l,c);
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends