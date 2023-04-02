class Solution {
    private:
    int n;
    int m;
    long long total = 0;
    vector<vector<vector<int>>> hash;
    vector<vector<int>> appels;
    void slice(int i_, int j_,int k)
    {
        if (hash[i_][j_][k] != -1)
        {   // use addition from hask  (for given k at point)
            total += hash[i_][j_][k];
            return;
        }
        long long save = total;
        if (k==0)
        {

            total++;
            return;
        }
        for(int i=i_+1; i<n; i++)
        {   // if apple above and under cut is valid
            if(appels[i][j_] >= k && appels[i_][j_] >  appels[i][j_])
              slice(i,j_,k-1);
        }
        for(int j=j_+1; j<m; j++)
        {   // if apple on left and apple on write, cut is valid
            if(appels[i_][j] >= k  && appels[i_][j_] > appels[i_][j])
              slice(i_,j,k-1);  // cut is valid => continue
         }
        hash[i_][j_][k] = total - save;  // remember addition at point
        return;
    }
public:
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].length();
        hash.resize(n,vector<vector<int>>(m,vector<int>(k,-1)));
        appels.resize(n,vector<int>(m,0));
        for(int i=n-1; i>=0; i--)
        {   // calculate appels from point to right down corner
            // this information will ditrmine if cut is valid at point
            int ai = 0;
            for(int j=m-1; j>=0; j--)
            {
                if (pizza[i][j] == 'A') ai++;
                if (i<n-1)
                    appels[i][j]= appels[i+1][j] + ai; 
                else 
                    appels[i][j]= ai;
            }
        }
        if (appels[0][0]<k) return 0;
          slice(0,0,k-1);
        return total%1000000007;
    }
};