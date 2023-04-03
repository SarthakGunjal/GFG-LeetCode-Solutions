//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       int z = x[0] - '0';
       for(int i = 1;i<x.length();i++)
       {
           int k = x[i] - '0';
           if(k>=z)
           {
               z = k - z;
           }
           else{
               z--;
               k+=10;
               
               z = k - z;
           }
       }
       
       return z;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends