class Solution {
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int m,int n,int drow,int dcol,int &sum){
        
        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};
        
        
       
           visited[drow][dcol]=1;
            sum+=grid[drow][dcol];
            
            
            for(int i=0; i<4;i++){
                int nrow=drow+row[i];
                int ncol=dcol+col[i];
                
                if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]>0){
                    dfs(grid,visited,m,n,nrow,ncol,sum);
                    
                }
            }
            
        
       
        // return sum;
    }
    
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        
        int maxi=0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // stack<pair<pair<int,int>,int>>s;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]>0 && !visited[i][j]){
                  int sum=0;
                    // s.push({{i,j},grid[i][j]});
                    dfs(grid,visited,m,n,i,j,sum);
                     maxi=max(maxi,sum);
                    // cout<<endl;
                }
                
                
            }
        }
        
        
        return maxi;
        
    }
};