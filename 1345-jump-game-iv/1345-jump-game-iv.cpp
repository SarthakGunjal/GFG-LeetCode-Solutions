class Solution {
public:
    // bfs
    int minJumps(vector<int>& arr) {
        unordered_set<int> v = {0, -1, (int) arr.size()};
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < arr.size(); ++i) m[arr[i]].insert(i);
        int ans = 0;
        queue<int> bfs;
        bfs.push(0);
        while (!bfs.empty()){
            for (int i = bfs.size(); i > 0; --i){
                int n = bfs.front();
                bfs.pop();
                if (n == arr.size() - 1) return ans;
                if (v.find(n - 1) == v.end()){
                    bfs.push(n - 1);
                    v.insert(n - 1);
                }
                if (v.find(n + 1) == v.end()){
                    bfs.push(n + 1);
                    v.insert(n + 1);
                }
                vector<int> del = {n};
                for (auto& ind : m[arr[n]]){
                    if (v.find(ind) == v.end()){
                        bfs.push(ind);
                        v.insert(ind);
                        del.push_back(ind);
                    }
                }
                for (auto& toDel : del)
                    m[arr[n]].erase(toDel);
            }
            ++ans;
        }
        return -1;
    }
};