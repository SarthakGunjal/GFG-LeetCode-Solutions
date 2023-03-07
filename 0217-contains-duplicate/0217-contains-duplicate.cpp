class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> my_hash;

        for(int i=0; i< nums.size(); i++)
        {
            if(my_hash.count(nums[i]))
                return true;
            my_hash.insert(nums[i]);
        }
        return false;
    }
};