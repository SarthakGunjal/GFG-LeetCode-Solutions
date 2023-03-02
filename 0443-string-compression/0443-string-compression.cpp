class Solution {
public:
    int compress(vector<char>& chars)
     {
      string ans;
      int count=1;
      int n=chars.size();
      if(n==1)
      {
          return 1;
      }
      ans.push_back(chars[0]);
      for(int i=1;i<n;i++)
      {
          if(chars[i]==chars[i-1])
          {
              count++;
          }
            else
             {
             if(count>1)
              {
                ans+=to_string(count);
              }
              count=1;
              ans.push_back(chars[i]);
             }
      }
       if(count>1)
       {
           ans+=to_string(count);
       }
       int m=ans.size();
       for(int i=0;i<m;i++)
       {
         chars[i]=ans[i];
       }
       return ans.size();
    }    
};