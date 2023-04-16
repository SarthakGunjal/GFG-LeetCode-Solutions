class Solution {
    int M = 1e9 + 7, m, n;
public:
    int numWays(vector<string>& words, string target) {
        
        m = target.size(), n = words[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1)), dp2(n, vector<int> (26, 0));

        for(int i = 0; i < n; i++)
            for(auto &j : words)
                dp2[i][j[i] - 'a']++;

        return helper(words, target, 0, 0, dp, dp2);
    }

    long long helper(vector<string> &words, string &target, int i, int k, vector<vector<int>> &dp, vector<vector<int>> &dp2)
    {
        if(i >= m)
            return 1;

        if(k >= n)
            return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        long long tmp = helper(words, target, i, k + 1, dp, dp2);
        if(dp2[k][target[i] - 'a'])
            tmp = (tmp + (dp2[k][target[i] - 'a'] * helper(words, target, i + 1, k + 1, dp, dp2)) % M) % M;

        return dp[i][k] = tmp;
    }
};