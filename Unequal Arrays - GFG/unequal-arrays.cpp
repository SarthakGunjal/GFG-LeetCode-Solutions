//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
   long long solve(int N, vector<int> &A, vector<int> &B) {
        int s1=0,s2=0;
        vector<int> A1,A2,B1,B2;
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        for(int i=0;i<N;i++)
        {
            if(A[i]%2==0)
            {
                A1.push_back(A[i]);
            }
            else
            {
                A2.push_back(A[i]);
            }
                
            if(B[i]%2==0)
            {
                B1.push_back(B[i]);
            }
            else
            {
                B2.push_back(B[i]);
            }
            s1+=A[i];
            s2+=B[i];
        }
        if(s1!=s2 || A1.size()!=B1.size())
            return -1;
            
        int increase=0,decrease=0;
        for(int i=0;i<A1.size();i++)
        {
            if(A1[i]<B1[i])
            {
                increase+= (B1[i]-A1[i])/2;
            }
            else if(A1[i]>B1[i])
            {
                decrease+= (A1[i]-B1[i])/2;
            }
            
        }
        
        for(int i=0;i<A2.size();i++)
        {
            if(A2[i]<B2[i])
            {
                increase+= (B2[i]-A2[i])/2;
            }
            else if(A2[i]>B2[i])
            {
                decrease+= (A2[i]-B2[i])/2;
            }
        }
        
        if(increase!=decrease)
        {
            return -1;
        }
        return increase;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends