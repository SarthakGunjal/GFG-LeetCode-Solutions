class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        int n = p.size();
        vector<vector<int>>dp(n,vector<int>(k+1,0));

        for(int i = 0;i<n;i++)dp[i][0] = 0;
        int sum = 0;
        for(int i = 1;i<=k and i<=p[0].size();i++){
            sum = sum + p[0][i-1];
            dp[0][i] = sum;
        }

        for(int i = 1;i<n;i++){
            for(int j = 1;j<=k;j++){
                int notake = dp[i-1][j];
                int take = 0;
                int sum = 0;
                for(int kk = 1;kk<=j and kk<=p[i].size();kk++){
                    sum = sum + p[i][kk-1];
                    take = max(take,sum + dp[i-1][j-kk]);
                }
                dp[i][j] = max(take,notake);
            }
        }
        return dp[n-1][k];
    }
};