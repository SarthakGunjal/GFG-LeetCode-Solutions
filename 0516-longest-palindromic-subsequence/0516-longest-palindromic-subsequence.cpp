class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revS=s;
        reverse(revS.begin(),revS.end());
        int n=s.size();
        vector<int>prev(n+1,0);
       vector<int>curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==revS[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};