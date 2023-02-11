class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> g(n);
        vector<vector<bool>> visited(2,vector<bool>(n,false));
        for(auto it:redEdges)
            g[it[0]].push_back({it[1],0});
        for(auto it:blueEdges)
            g[it[0]].push_back({it[1],1});
        vector<int> ans(n,-1);
        queue<pair<int,int>> q;
        q.push({0,2});
        visited[0][0]=true;
        visited[1][0]=true;
        int dist=0;
        ans[0]=dist;
        while(!q.empty())
        {
            int qs=q.size();
            ++dist;
            for(int k=0;k<qs;++k)
            {
                int snode=q.front().first,color=q.front().second;
                q.pop();
                for(int i=0;i<g[snode].size();++i)
                {
                    if(g[snode][i].second!=color&&!visited[g[snode][i].second][g[snode][i].first])
                    {
                        visited[g[snode][i].second][g[snode][i].first]=true;
                        if(ans[g[snode][i].first]==-1)
                            ans[g[snode][i].first]=dist;
                        q.push({g[snode][i].first,g[snode][i].second});
                    }
                }
            }
            
        }
        return ans;
    }
};
