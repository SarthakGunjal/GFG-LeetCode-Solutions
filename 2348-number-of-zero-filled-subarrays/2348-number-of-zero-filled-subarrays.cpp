
    class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long count = 0,ans=0;
        for(long i : nums){
            if(i==0) {count++;continue; }
            ans = ans + (count*(count+1))/2;
            count = 0;
        }
        ans = ans + (count*(count+1))/2;
        return ans;
    }
};
