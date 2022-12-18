//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> vect, long long n, long long m){
    sort(vect.begin(),vect.end());
    vector <long long>ans;
    for(int i =0 ; i<n; i++){
        
        ans.push_back(vect[i+m-1]-vect[i]);
        if(i+m==n) break;
    }
    // long long a= min_element(ans.begin(),ans.end());
    long long min=INT_MAX;
     for(int i =0 ; i<ans.size() ; i++){
        if(ans[i]<min){
            min=ans[i];
        }
    }
    return min;
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends