class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mp;

        while(n!=1){
            int sum = 0, current = n;

            while(current){
                int digit = current % 10;
                sum += (digit * digit);
                current /= 10;
            }

            if(mp.find(sum)!=mp.end())
                return false;

            mp[sum]++;
            n = sum;
        }

        return true;

    }
};