class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());

        int sum = 0;
        int cur = 0;
        int ans = 0;

        for (int i{n-1};i>=0;i--){
            cur += sum + satisfaction[i];
            sum += satisfaction[i];
            ans = max(ans,cur);
            if (ans != cur)
                break;
        }
        return ans;
    }
};