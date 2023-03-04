class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        bool flag = true ;
        int m = word1.length() , n = word2.length() , i, j ;
        i = 0, j = 0;
        while(i<m && j<n)
        {
            if(flag){
                ans+= word1[i] ;
                flag = false ;
                i++;
            }
            else{
                ans+= word2[j] ;
                flag = true ;
                j++;
            }
        }
        while(i<m){
            ans+= word1[i] ;
            i++;
        }
        while(j<n){
            ans+= word2[j] ;
            j++;
        }
        return ans ;
    }
};