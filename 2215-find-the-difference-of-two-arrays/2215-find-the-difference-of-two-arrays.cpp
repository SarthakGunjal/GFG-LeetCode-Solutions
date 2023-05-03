class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        
        int n2 = nums2.size();
        
        // declare two sets
        
        unordered_set<int> s1;
        
        unordered_set<int> s2;
        
        // inbsert elements of nums1 into s1
        
        for(int i = 0; i < n1; i++)
        {
            s1.insert(nums1[i]);
        }
        
        // insert elements of nums2 into s2
        
        for(int i = 0; i < n2; i++)
        {
            s2.insert(nums2[i]);
        }
        
        vector<int> res1;
        
        vector<int> res2;
        
        // now traverse over s1 and create res1
        
        for(auto x : s1)
        {
            if(s2.count(x) == 0)
            {
                res1.push_back(x);
            }
        }
        
        // now traverse over s2 and create res2
        
        for(auto x : s2)
        {
            if(s1.count(x) == 0)
            {
                res2.push_back(x);
            }
        }
        
        return {res1, res2};
    }
};