class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack<int> st;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()) st.pop();
            if(st.empty()){
                st.push(nums2[i]);
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};