//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution {
    public:
    vector<int> JobScheduling(Job arr[], int n) { 
        map<int, vector<int>> m;
        for(int i=0; i<n; i++) m[arr[i].dead].push_back(arr[i].profit);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto i : m) {
            int s = i.first;
            vector<int> v = i.second;
            for(int i : v) {
                pq.push(i);
                if(pq.size() > s) pq.pop();
            }
        }
        int a = pq.size(), b = 0;
        while(pq.size()) b += pq.top(), pq.pop();
        
        return {a, b};
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends