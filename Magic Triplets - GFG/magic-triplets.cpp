//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
int countTriplets(vector<int>nums){
	    // Code here.
	    
	    int n=nums.size();
	    int cnt=0;
	    for(int i=1;i<n-1;++i){
	        int x=0;
	        int y=0;
	        int z1=i-1,z2=i+1;
	        while(z1>=0){if(nums[z1]<nums[i]){x++;}z1--;}
	        while(z2<n){if(nums[z2]>nums[i]){y++;}z2++;}
	        if(x || y)cnt+=(x*y);
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends