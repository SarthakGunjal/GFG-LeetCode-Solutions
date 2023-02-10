class Solution {
public:

    int NP = 201;

    bool isValid(int x, int y, int n){
        if(x >= 0 && x < n && y >= 0 && y < n) return true;
        else return false;
    }

    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, NP)), vis(n, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){

            pair<int,int> node = q.front();
            q.pop();

            int i = node.first, j = node.second;
            int x = i - 1, y = j;
            if(isValid(x, y, n) && vis[x][y] == 0){
                dist[x][y] = min(dist[x][y], 1 + dist[i][j]);
                vis[x][y] = 1;
                q.push({x, y});
            }

            x = i + 1, y = j;
            if(isValid(x, y, n) && vis[x][y] == 0){
                dist[x][y] = min(dist[x][y], 1 + dist[i][j]);
                vis[x][y] = 1;
                q.push({x, y});
            }

            x = i, y = j - 1;
            if(isValid(x, y, n) && vis[x][y] == 0){
                dist[x][y] = min(dist[x][y], 1 + dist[i][j]);
                vis[x][y] = 1;
                q.push({x, y});
            }

            x = i, y = j + 1;
            if(isValid(x, y, n) && vis[x][y] == 0){
                dist[x][y] = min(dist[x][y], 1 + dist[i][j]);
                vis[x][y] = 1;
                q.push({x, y});
            }

        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dist[i][j]);
            }
        }

        if(ans == 0 || ans == 201) return -1;
        return ans;

    }
};