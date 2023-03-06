class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i;
        k-=arr[0]-1;
        if(k<=0)return abs(k+arr[0]-1);
        for(i=0;i<arr.size()-1;i++){
            int diff=arr[i+1]-arr[i];
            if(diff!=1){
                diff--;
                if(diff>=k)return arr[i]+k;
                else k-=diff;
            }
        }
        return arr[i]+k;
    }
};
