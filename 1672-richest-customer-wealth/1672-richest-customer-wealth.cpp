class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
         //vector<int> ans;
        int m = a.size();
        int n = a[0].size();
        int maxi = INT_MIN;
      for(int i=0;i<m;i++){
          int sum =0;
          for(int j=0;j<n;j++){
            sum += a[i][j];
          }
       maxi = max(maxi,sum);   
      }
      return maxi;
    }
};