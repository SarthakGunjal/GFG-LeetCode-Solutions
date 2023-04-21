class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>>memo;
    int helper(int n, int i, int p,vector<int>& group, vector<int>& profit){
        if(n<0) return 0;
        if(i==group.size()){
            if(p<=0) return 1;
            else return 0;
        }
        if( memo[i][p][n]!=-1) return  memo[i][p][n];
        int include=helper(n-group[i],i+1,max(0,p-profit[i]),group,profit);
        int exclude=helper(n,i+1,p,group,profit);
        return memo[i][p][n]=(include+exclude)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memo=vector<vector<vector<int>>>(group.size(),vector<vector<int>>(minProfit+1,vector<int>(n+1,-1)));
        return helper(n,0,minProfit,group,profit);
    }
};