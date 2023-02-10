class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minDiff  = INT_MAX;
        int i = 0;
        int start = i+1;
        int end = nums.size()-1;
        int sum = 0;
        int ans = 0 ;

        while(i<nums.size()-2){
            start = i+1;
            end = nums.size()-1;
            while(start<end){
            sum = nums[i]+nums[start]+nums[end];
            if(abs(sum - target) < minDiff){
                ans = sum;
                minDiff = abs(sum - target);
            }

            if(sum>target) end--;
            else
            start++;
           }
            i++;
        }
        return ans;
    }
};