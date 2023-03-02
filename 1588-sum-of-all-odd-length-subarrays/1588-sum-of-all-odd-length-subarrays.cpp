class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        for(int i = 3;i<=arr.size();i+=2){
            int val = accumulate(arr.begin(),arr.begin()+i,0);
            sum += val;
            for(int j=i;j<arr.size();j++){
                val += arr[j] - arr[j-i];
                sum += val;
            }
        }
        return sum;
    }
};