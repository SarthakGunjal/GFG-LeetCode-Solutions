class Solution {
private:
    unordered_map<string,bool> mp;
public:
    bool eql(vector<int> &arr1, vector<int> &arr2){
        for(int i=0;i<26;++i){
            if(arr1[i]!=arr2[i])return false;
        }
        return true;
    }

    bool isScramble(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int n = s1.size();
        if(mp.find(s1+s2) != mp.end()) return mp[s1+s2];
        mp[s1+s2] = false;
        vector<int> cnt(26,0);
        vector<int> cnt2(26,0);
        vector<int> cnt3(26,0);
        for(int i=1; i<n; i++) {
            cnt[s1[i-1]-'a']++;
            cnt2[s2[i-1]-'a']++;
            cnt3[s2[n-i]-'a']++;
            if(eql(cnt, cnt3)){
                if(isScramble(s1.substr(0,i), s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i), s2.substr(0,n-i))){
                    mp[s1+s2]=true;
                    return true;
                }
            }
            if(eql(cnt, cnt2)){
                if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,n-i), s2.substr(i,n-i))){
                    mp[s1+s2]=true;
                    return true;
                }
            }
        }
        return false;
    }
};