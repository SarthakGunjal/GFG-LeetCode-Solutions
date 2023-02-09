class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_map<string , int> mp;

        for(auto it:ideas){
            mp[it]++;
        }

        vector<vector<long long>> store(26 , vector<long long>(26 , 0));

        for(int i=0 ; i<ideas.size() ; i++){
            string word = ideas[i].substr(1);
            int ch = ideas[i][0]-'a';
            for(int j=0 ; j<26 ; j++){
                char t = (j+'a');
                string temp = t + word;
                if(mp.count(temp) == 0){
                    store[ch][j] += 1;
                }
            }
        }
        for(int i=0 ; i<26 ; i++){
            for(int j=0 ; j<26 ; j++){
                if(i==j) continue;
                if(store[i][j] > 0){
                    ans += store[j][i]*store[i][j];
                }
            }
        }
        return ans;
    }
};