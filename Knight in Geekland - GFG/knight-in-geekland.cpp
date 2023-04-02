//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        
        queue<pair< int , int >>q ;
        
        q.push({ start_x , start_y }) ;
        
        vector<int>v ;
        
        v.push_back(arr[start_x][start_y]) ;
        
        int m = arr.size() ;
        int n = arr[0].size() ;
        
        vector<vector<bool>>vis( m , vector<bool>( n , false)) ;
        vis[start_x][start_y] = true ;
        
        
        int xr[8] = { 2 , 2 , -2 , -2 , 1 , -1 , 1 , -1 } ;
        int yr[8] = { -1 , 1 , 1 , -1 , 2 , 2 , -2 , -2 } ;
        
        
        while(!q.empty())
        {
            int sz = q.size() ;
            int p = 0 ;
            for( int i = 0 ; i < sz ; i++ )
            {
            auto it = q.front() ;
            q.pop() ;
            
            int x = it.first  ;
            int y = it.second ;
           
            
            for( int j = 0 ; j < 8 ; j++ )
            {
                int nx = x + xr[j] ;
                int ny = y + yr[j] ;
                
                if( nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] )
                {
                    vis[nx][ny] = true ;
                    q.push({ nx , ny }) ;
                    p += arr[nx][ny] ;
                }
            }
            
            }
            
            v.push_back(p) ;
           
        }
        
        
        int ans = 0 ;
        int mx =  v[0] ;
        
        int l = v.size() ;
        vector<bool>f( l , false ) ;
        for( int i = 0 ; i < l ; i++ )
        {
            int t = v[i] ;
            int j = i    ;
            int vl = v[i] ;
            f[i] = false ;
            if( vl != 0 )
            {
               while( j + vl < l && !f[j+vl] )
            {
                f[j+vl] = true ;
                t += v[j+vl] ;
                int temp = j ;
                j = j + vl   ;
                vl = v[vl+temp] ;
                
            }
            
            }
            
            
            if( t > mx )
            {
                mx = t ;
                ans =i ;
            }
            
            
        }
       
            
            return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends