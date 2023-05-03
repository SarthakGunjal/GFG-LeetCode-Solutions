//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   bool isPal(string str){
        string s = str;
        reverse(s.begin(), s.end());
        if (str == s) return true;
        return false;
    }
    bool makePalindrome(int n,vector<string> &v){
        string s;
        bool ans = true;
        map<string, int> mp;
        for(auto str:v) {
            mp[str]++;
            s = str;
            reverse(s.begin(), s.end());
            mp[s];
        }
        set<string> vs;
        for(auto pr:mp){
            s = pr.first;
            reverse(s.begin(), s.end());
            auto it = mp.find(s);
            if (pr.second>(*it).second) vs.insert(pr.first);
            else if (pr.second < (*it).second) vs.insert(s);
        }
        for(auto str:vs) if (!isPal(str)) ans = false;
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
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends