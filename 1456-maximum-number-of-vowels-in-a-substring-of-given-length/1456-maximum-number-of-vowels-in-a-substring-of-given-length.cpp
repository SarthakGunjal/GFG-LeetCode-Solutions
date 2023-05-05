class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vol = 0 , i=0 ,j=0 ;
        while(i<k){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u') max_vol++ ;
            i++ ;
        }
        int temp = max_vol ;
        while(i<s.length()){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o'|| s[j]=='u') temp-- ;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u') temp++ ;
            j++ ;
            i++ ;
            max_vol = max(max_vol , temp);
        }
        return max_vol ;
    }
};