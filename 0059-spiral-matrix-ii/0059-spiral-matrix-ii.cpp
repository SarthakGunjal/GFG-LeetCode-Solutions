class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n,vector<int>(n));
        int l=0,r=n-1,up=0,down=n-1;  
        int dir=0;
        int val=1;
        while(l<=r && up<=down)
        {
            if(dir==0)
            {
               for(int i=l;i<=r;i++) {
                   v[up][i]=val++;
               }
               up++;
               dir=(dir+1)%4;
            }
            else if(dir==1)
            {
                for(int i=up;i<=down;i++)
                {
                    v[i][r]=val++;
                }
                r--;
                dir=(dir+1)%4;
            }
            else if(dir==2)
            {
              for(int i=r;i>=l;i--)
              {
                  v[down][i]=val++;
              }
              down--;
              dir=(dir+1)%4;
            }
            else{
                for(int i=down;i>=up;i--)
                {
                    v[i][l]=val++;
                }
                l++;
                dir=(dir+1)%4;
            }
        }
        return v;
    }
};