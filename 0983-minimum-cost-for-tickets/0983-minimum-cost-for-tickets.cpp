class Solution {
public:
    vector<int> dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(),-1);
        return dfs(0,days,costs);
    }

    int dfs(int i,vector<int> &days,vector<int> &cost){
        if(i>=days.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int c= cost[0]+dfs(i+1,days,cost);

        auto seven=lower_bound(days.begin()+i,days.end(),days[i]+7);
        int idx1=seven-days.begin();
        c=min(c,cost[1]+dfs(idx1,days,cost));

        auto thirty=lower_bound(days.begin()+i,days.end(),days[i]+30);
        int idx2=thirty-days.begin();
        c=min(c,cost[2]+dfs(idx2,days,cost));

        return dp[i]=c;
    }
};