#define ll long long
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        ll mini = nums[0];
        ll sum = nums[0];
        for(ll i=1;i<nums.size();i++){
          sum+= nums[i];
          if(nums[i]>mini){
            ll x = sum/(i+1);
            if(x>=mini){
              if(sum%(i+1))mini=x+1;
              else mini = x;
            }
          }
        }

        return mini;
    }
};