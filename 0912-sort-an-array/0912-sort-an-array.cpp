class Solution {
public:
    void merge_sort_compile(vector<int>&nums,int start,int mid ,int end)
    {
       int i=start;
       int j=mid+1;
       int k = 0;
       vector<int>temp(end-start+1);
       while(i<=mid && j<=end)
       {
           if(nums[i]<=nums[j]) temp[k++] = nums[i++];
           else temp[k++] = nums[j++];
       }
       while (i <= mid)
       {
            temp[k++] = nums[i++];
       }
        while (j <= end)
        {
            temp[k++] = nums[j++];
        }
        for(int m=0;m<k;m++) nums[start+m] = temp[m];
    }
    void merge_sort_breakdown(vector<int>&nums,int start,int end)
    {
        int mid = start+(end-start)/2;
        if(start>=end) return;
        merge_sort_breakdown(nums,start,mid);
        merge_sort_breakdown(nums,mid+1,end);
        merge_sort_compile(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums)
    {
        int n = nums.size();
        merge_sort_breakdown(nums,0,n-1);
        return nums; 
    }
};