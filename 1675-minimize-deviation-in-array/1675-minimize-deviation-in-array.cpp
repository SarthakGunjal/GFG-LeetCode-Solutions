class Solution {
public:
   
    int minimumDeviation(vector<int>& nums) {
        int val,mini=INT_MAX,mx=0;
        priority_queue<int>pq;
        for(auto &x:nums){
            if(x&1){
              val=x*2;   
            }else val=x;
            mini=min(mini,val);
            mx=max(mx,val);
            pq.push(val);
        }
        int diff=mx-mini;
        while(pq.size() && (mx&1)==0){
         mx=pq.top();pq.pop();
         diff=min(diff,mx-mini);
         val=mx/2;
         mini=min(mini,val);
         pq.push(val);
        }
        diff=min(diff,mx-mini);
        return diff;
    }
};