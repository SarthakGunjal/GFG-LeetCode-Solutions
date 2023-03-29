//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        int low=0, up=0, count=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                char temp= s[j];
                if(islower(temp)){
                    low++;
                }
                else{
                    up++;
                }
                if(low==up){
                    count++;
                }
            }
            low=0, up=0;
          
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends