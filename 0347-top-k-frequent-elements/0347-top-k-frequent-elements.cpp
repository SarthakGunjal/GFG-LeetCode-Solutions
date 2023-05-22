class Solution {
public:
static bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second>b.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        vector<pair<int,int>>temp;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            temp.push_back(make_pair(it.first,it.second));
        }
        sort(temp.begin(),temp.end(),cmp);
        
        for(int i=0;i<k;i++){
            
            v.push_back(temp[i].first);
            
        }
        
        return v;
    }
};
