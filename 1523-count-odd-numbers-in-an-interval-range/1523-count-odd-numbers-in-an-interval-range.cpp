class Solution {
public:
      int countOdds(int low, int high) {
        if(high==low) {
            if(high%2==0) return 0;
            return 1;
        }
        if((high+low)%2==0) {
            if(high%2==0)  return (high-low)/2;                     
            else return (high-low-1)/2 + 2;                 
        } 
        return (high-low-1)/2 + 1;
    }
};