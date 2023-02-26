class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.size();
        int m = (int)word2.size();
        //dp[i][j] is the minimum number of operations to convert word1[0..i) to word2[0..j)
        int dp[n + 1][m + 1];
        //base case
        for(int i = 0; i <= n; ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j <=m; ++j){
            dp[0][j] = j;
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                }
            }
        }
        return dp[n][m];
    }
};