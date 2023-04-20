class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                long long toFind = (long long) target - (long long)(nums[i] + nums[j]);
                int low = j+1, high = n-1;
                while(low < high){
                    long long found = nums[low] + nums[high];
                    if(found == toFind){
                        ans.insert({ nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    } else if(found < toFind) low++;
                    else high--;
                }
            }
        }
        return vector(ans.begin(), ans.end());
    }
};
