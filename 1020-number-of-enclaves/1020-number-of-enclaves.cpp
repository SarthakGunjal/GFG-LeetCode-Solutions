class Solution {
    private :
    void dfs(int x,int y,int m,int n,vector<vector<int>>&grid,vector<vector<bool>>&visit){
        if(x>=m||x<0||y>=n||y<0||grid[x][y]==0||visit[x][y]){
            return;
        }
        visit[x][y]=true;
        vector<int>dx{0,1,0,-1};
        vector<int>dy{-1,0,1,0};
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i],m,n,grid,visit);
        }
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        vector<vector<bool >>visit(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1&&!visit[i][0]){
                dfs(i,0,m,n,grid,visit);
            }
            if(grid[i][n-1]==1&&!visit[i][n-1]){
                dfs(i,n-1,m,n,grid,visit);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1&&!visit[0][i]){
                dfs(0,i,m,n,grid,visit);
            }
            if(grid[m-1][i]==1&&!visit[m-1][i]){
                dfs(m-1,i,m,n,grid,visit);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 &&!visit[i][j]){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};