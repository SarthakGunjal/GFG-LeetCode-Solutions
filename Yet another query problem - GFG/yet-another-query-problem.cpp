//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:

    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {

        // code here

        vector<int > ans;

        unordered_map<int ,int> m;

        for(int z=0;z<N;z++){

            m[A[z]]++;

        }

        for(int i=0;i<num;i++){

            int ct=0;

            int l=Q[i][0];

            int r=Q[i][1];

            int s=Q[i][2];

        for(int e=0;e<l;e++){

            m[A[e]]--;

        }

            for(int j=l;j<=r;j++){   

                int c = m[A[j]];

                m[A[j]]--;

                if(c==s){

                    ct++;

                }

            }

            for(int k=0;k<=r;k++){

                m[A[k]]++;

            }

         ans.push_back(ct);

                    }                

        return ans;

    }

};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends