class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minel=prices[0];
        int max_prof=0;

        for(int i =0 ; i<prices.size();i++){
            minel= min(minel,prices[i]);
            int prof= (prices[i]-minel);
            max_prof= max(prof,max_prof);

        }
        return max_prof;
    }
};