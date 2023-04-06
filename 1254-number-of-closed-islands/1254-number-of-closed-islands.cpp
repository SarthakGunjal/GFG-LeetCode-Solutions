class Solution {
public:
    void solve(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& vis){
         vis[x][y]=1;
             int di[]={1,-1,0,0};
            int dj[]={0,0,-1,1};
                int n=grid.size();
                int m=grid[0].size();
        for(int i=0;i<4;i++){
            int newX=x+di[i];
            int newY=y+dj[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && vis[newX][newY]==0 && grid[newX][newY]==0){
                solve(newX,newY,grid,vis);
            }
        }  
    }
    int closedIsland(vector<vector<int>>& grid) {
        
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
       if(grid[i][0]!=1 && vis[i][0]==0){
                solve(i,0,grid,vis);
            }
        if(grid[i][m-1]!=1 && vis[i][m-1]==0){
        solve(i,m-1,grid,vis);
    }

    }
     for(int j=1;j<m-1;j++){
        if(grid[0][j]!=1 && vis[0][j]==0){
            solve(0,j,grid,vis);
        }
        if(grid[n-1][j]!=1 && vis[n-1][j]==0){
            solve(n-1,j,grid,vis);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]==0){
                ans++;
                solve(i,j,grid,vis);
            }
        }
    }
    return ans;

    }
};