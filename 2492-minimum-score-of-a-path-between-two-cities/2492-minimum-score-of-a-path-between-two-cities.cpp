class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> paths[n + 1];

        for (auto &road : roads) {
            paths[ road[0] ].push_back( {road[1], road[2]} );
            paths[ road[1] ].push_back( {road[0], road[2]} );
        }

        queue<int> values;
        values.push(1);
        int ans = 1e5;

        vector<bool> visited(n + 1, false);
        visited[1] = true;

        while (!values.empty()) {
            int node = values.front();
            values.pop();

            for (auto &allroads : paths[node]) {
                if (!visited[allroads.first]) {
                    values.push( allroads.first );
                    visited[ allroads.first ] = true;
                }

                ans = min(ans, allroads.second);
            }
        }

        return ans;
    }
};