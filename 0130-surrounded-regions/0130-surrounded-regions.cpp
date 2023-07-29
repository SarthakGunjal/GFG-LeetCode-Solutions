class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        stack<pair<int,int>>s;
        int m = board.size();//X
        int n = board[0].size();//Y
        
        int visited[m][n];
        
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O'){
                    s.push({i,j});
                    visited[i][j]={1};
                }
                else visited[i][j]={0};
            }
        }
        
        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};
        
        while(!s.empty()){
            
            int i = s.top().first;
            int j = s.top().second;
            s.pop();
            
            for(int k=0; k<4; k++){
                
                int nrow = row[k]+i;
                int ncol = col[k]+j;
                
                if((nrow>=0 && nrow<m && ncol>=0 && ncol<n)&& !visited[nrow][ncol]  && board[nrow][ncol]=='O' ){
                    visited[nrow][ncol]=1;
                    s.push({nrow,ncol});
                }
            }
            
            
        }
        
        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j]==1) board[i][j]='O';
                else board[i][j]='X';
            }
        }
        
        
    }
};