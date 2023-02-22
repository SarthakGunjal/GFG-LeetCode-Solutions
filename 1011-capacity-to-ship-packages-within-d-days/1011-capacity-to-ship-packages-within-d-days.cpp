class Solution {
public:
    bool check(vector<int> &a,int k,int cap)
    {
        int n=a.size();
        int day=0;
        int sum=0,s=0;
        while(1)
        {
            while(s<n && sum<=cap)
            {
                if(a[s]>cap)return 0;
                if(sum+a[s]>cap)break;
                sum+=a[s];
                s++;
            }
            if(s==n)
            {
                day++;
                break;
            }
            sum=0;
            day++;
        }
        return day<=k;
    }
    int shipWithinDays(vector<int>& a, int k) {
        int n=a.size();
        int s=1,e=0;
        for(int i=0;i<n;i++)s=max(s,a[i]),e+=a[i];
        int ans=e;
        while(s<=e)
        {
            int mid=(e-s)/2+s;
            if(check(a,k,mid))ans=mid,e=mid-1;
            else s=mid+1;
        }
        return ans;
    }
};