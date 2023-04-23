#define ll long long

class Solution {
public:
    ll solve(int i,string& s,int &k,ll num,vector<vector<ll>>& dp,int digit){
        if(i==s.size() && num<=k && num>0) return 1;
        else if(i==s.size()) return 0;
        num = num*10 + (s[i]-'0');
        if(dp[i][digit] != -1) return dp[i][digit];
        // cout<<num<<endl;
        if(num > k) return 0;
        ll ans = 0;
        if(num <=k && num > 0){
            ans += solve(i+1,s,k,0,dp,0);
        }
        if(num != 0){
           ans += solve(i+1,s,k,num,dp,digit+1);
        }
        
        return dp[i][digit]=ans%1000000007;
    }
    int numberOfArrays(string s, int k) {
        vector<vector<ll>> dp(s.size(),vector<ll>(11,-1));
        return solve(0,s,k,0,dp,0);
    }
};