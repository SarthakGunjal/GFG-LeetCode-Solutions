//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      
      long long  pr1=0 , rp1=0 , pr2=0,rp2=0;
      string s1 = S;
      
       if( X > Y ){
          for( int i=0; i<s1.length() && i>= 0 ; )
          {
          
            if(s1[i] =='p' && s1[i+1] == 'r')
            {
              pr1+=1;
              s1.erase(i,2);
                 i-=2;
            }
              i++;
              if(i<0)i=0;
           }
      
          for( int i=0; i<s1.length() && i>= 0 ; ){
            if(s1[i] =='r' && s1[i+1] == 'p'){
              rp1+=1;
              s1.erase(i,2);
              
                 i-=2;
              }
               i++;
               if(i<0)i=0;
           }
           
           return pr1*X+rp1*Y;
      }
      
      else{
           for( int i=0; i<s1.length() && i>= 0 ; )
          {
          
            if(s1[i] =='r' && s1[i+1] == 'p')
            {
              rp2+=1;
              s1.erase(i,2);
              
                 i-=2;
            }
              i++;
              if(i<0)i=0;
           }
          for( int i=0; i<s1.length() && i>= 0; ){
            if(s1[i] =='p' && s1[i+1] == 'r'){
              pr2+=1;
              s1.erase(i,2);
              
                 i-=2;
              }
               i++;
               if(i<0)i=0;
           }
           
           return pr2*X+rp2*Y;
      }
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends