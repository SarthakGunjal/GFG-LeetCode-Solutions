class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=1e9;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long time=0;
            for(auto i:piles)time+=(i+mid-1)/mid;
            if(time>h)left=mid+1;
            else right=mid-1;
        }
        return left;
    }
};