//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int i = 0;
        int left = 0, right = X,count = 0;
        while(i < N)
        {
            if(S[i] == '0')
            {
                count++;
                i++;
            }
            else
            {
                if(left + right < count)
                {
                    return false;
                }
                left = X;
                count = 0;
                i++;
            }
        }
        
        //cout << count << endl;
        if(S[S.length() - 1] == '0')
        {
            if(count > X)
             return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends