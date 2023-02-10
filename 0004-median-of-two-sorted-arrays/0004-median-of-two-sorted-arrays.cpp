class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums2.size();
        for( int i=0 ; i<n ; i++){
            nums1.push_back(nums2[i]);
        }
        
        sort(nums1.begin(),nums1.end());
       
        if(nums1.size()%2!=0)return nums1[nums1.size()/2];
        else {
           float k =(nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
           return (float)k;
       }
        
    }
};