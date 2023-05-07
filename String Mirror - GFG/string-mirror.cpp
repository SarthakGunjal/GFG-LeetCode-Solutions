//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int i=1;
        while(i<str.size()&&str[i]<=str[i-1])
        {
            if(str[i]==str[i-1]&&i==1)break;
            ++i;
        }
        string s=str.substr(0,i);
        string t=s;
        reverse(s.begin(),s.end());
        t+=s;
        return t;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends