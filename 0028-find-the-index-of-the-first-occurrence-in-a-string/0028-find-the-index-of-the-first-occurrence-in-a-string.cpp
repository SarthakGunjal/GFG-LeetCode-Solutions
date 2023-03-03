class Solution {
public:
    int strStr(string haystack, string needle) {
//         vector<int>s1(26,0);
//         vector<int>window(26,0);
//         for(int i=0;i<needle.size();i++){
//             s1[needle[i]]=1;
//             window[haystack[i]]=1;
//         }
        
//         if(s1==window)return 0;
//         int i,j=0;
        
// //         for(i=needle.size();i<haystack.size();i++){
// //             window[haystack[i]]=1;
// //             window[j]=0;
// //             j++;
// //             if(window==s1)return j;
            
// //         }
//         return -1;
//     }
    
    int n = haystack.length();
    int m = needle.length();

    // edge case
    if (m > n) {
        return -1;
    }

    // sliding window
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i+j] == needle[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }

    return -1;
    }
    };