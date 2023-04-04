class Solution {
public:
    int partitionString(string s) {
        int i =0;
        int j = s.length();
        int count=0;
        map<char,int>mp;
        while(i<j){
            
            if(mp.find(s[i])!=mp.end()){
                count++;
                mp.clear();
            }
            mp[s[i]]++;
            i++;
        }
        return count+1;
    }
};