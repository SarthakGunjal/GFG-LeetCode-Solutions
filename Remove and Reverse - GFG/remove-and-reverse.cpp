//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
     string removeReverse(string s) {
        vector<int> freq(26,0);
        int i = 0, j = s.length()-1;
        int cnt = 0;
        for(char c : s) {
            freq[c-'a']++;
        }
        
        bool rev = false;
        string a = "", b = "";
        
        while(i <= j) {
            char c;
            
            if(rev) c = s[j--];
            else c = s[i++];
            
            if(freq[c-'a'] > 1) {
                freq[c-'a']--;
                rev = !rev;
                cnt++;
            }
            else {
                if(rev) b = c + b;
                else a += c;
            }
        }
        
        s = a + b;
        if(cnt&1) reverse(s.begin(),s.end());
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends