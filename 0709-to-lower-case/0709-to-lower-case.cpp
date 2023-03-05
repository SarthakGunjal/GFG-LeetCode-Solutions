class Solution {
public:
    string toLowerCase(string s) {
        string s2="";
        for(char a: s)
        {
            if(a<=90 && a>=65)
            {
                s2+=a+32;
            }
            else{
                s2+=a;
            }

        }
        return s2;
    }
};