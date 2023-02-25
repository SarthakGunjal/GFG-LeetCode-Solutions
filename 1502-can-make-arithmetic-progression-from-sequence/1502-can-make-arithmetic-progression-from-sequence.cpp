class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dif=arr[1]-arr[0];
        
        for(int i=0;i<arr.size()-1;i++){
            cout<<arr[i];
            int dif2=arr[i+1]-arr[i];
            if(dif!=dif2)return 0;
        }
        return 1;
    }
};