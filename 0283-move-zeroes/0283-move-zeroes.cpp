class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int j = i;

        while(i < n){

            int k = nums[i];
            
            if(k == 0) j--;
            else{
                swap(nums[i], nums[j]);
            }

            i++;
            j++;
        }

    }
};