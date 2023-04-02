class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) { 
        vector<int>v;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){ 
            int s=0, e=potions.size()-1;
            int x = 0;
            bool f = false;
            while(s<=e){
                int mid = s+(e-s)/2;
                long long t =  (long long)spells[i] * (long long)potions[mid] ;
                if(t >= success){
                    x = mid;
                    e = mid-1;
                    f = true;
                }
                else s = mid+1;
            } 
            if(f)v.push_back(potions.size()-x);  
            else v.push_back(0);
        }
        return v; 
    }
};  
