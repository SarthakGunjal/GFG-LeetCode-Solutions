class Solution {
public:
     bool isAnagram(string s, string t) {
        map<char,int> map;
        if(s.size() != t.size()){
            return false;
        }
        for(int i =0;i<s.size();i++){
            map[s[i]]++;
        }
        for(int j=0;j<t.size();j++){
            if(map[t[j]]>0){
                map[t[j]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};