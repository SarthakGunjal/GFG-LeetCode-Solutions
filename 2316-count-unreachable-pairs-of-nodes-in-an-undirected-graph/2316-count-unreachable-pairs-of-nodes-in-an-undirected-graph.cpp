class Solution {
public:
        void dfs(int node, int par, vector<vector < int>> &adj, vector< int > &vis, int &k) //This function performs a depth-first search starting from a given node in the graph.It marks the current node as visited, increments a counter k which keeps track of the number of nodes in the current connected component, and recursively calls dfs on all unvisited neighbors.
    {
        vis[node] = 1;
        k++;
        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                dfs(it, node, adj, vis, k);
            }
        }
    }
        long long countPairs(int n, vector<vector < int>> &edges)  
        {
            vector<vector < int>> adj(n);
            for (auto it: edges)
            {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            vector<int> vis(n, 0);
            long long ans = 0, tot = 0;
            for (int i = 0; i < n; i++)
            {
                int k = 0;
                if (!vis[i])
                {
                    dfs(i, -1, adj, vis, k);
                }
                ans += k *(n - k - tot);
                tot += k;
            }
            return ans;
        }
};