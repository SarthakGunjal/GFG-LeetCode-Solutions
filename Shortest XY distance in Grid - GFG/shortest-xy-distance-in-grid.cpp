//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> &grid, int &r, int &c) {
    queue<int> q;
    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(grid[i][j] == 'Y')
                q.push(i * c + j);
        }
    }
    
    int lvl = 0;
    vector<vector<int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    };
    
    while(!q.empty()) {
        int size = q.size();
        
        while(size--) {
            int ele = q.front(); q.pop();
            int eleX = ele / c;
            int eleY = ele % c;
            
            if(grid[eleX][eleY] == 'X')
                return lvl;
            
            for(int i = 0; i < 4; ++i) {
                int nextX = eleX + dirs[i][0];
                int nextY = eleY + dirs[i][1];
                
                if(nextX < r && nextX >= 0 && nextY < c && nextY >= 0) {
                    if(grid[nextX][nextY] == 'X')
                        return lvl + 1;
                        
                    if(grid[nextX][nextY] == 'O') {
                        q.push(nextX * c + nextY);
                        grid[nextX][nextY] = 'Y';
                    }
                }
            }
        }
        
        ++lvl;
    }
    
    return lvl;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends