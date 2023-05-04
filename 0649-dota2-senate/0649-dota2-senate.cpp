class Solution {
public:
    string predictPartyVictory(string senate) {
        set<int> dIdx;
        set<int> rIdx;
        int n = senate.size();
        int dCount = 0, rCount = 0;
        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R') {
                rIdx.insert(i);
                rCount++;
            } else {
                dIdx.insert(i);
                dCount++;
            }
        }   
        while(dCount > 0 && rCount > 0) {
            for(int i = 0; i < n; i++) {
                if(senate[i] == 'R' && rIdx.count(i) > 0) {
                    dCount--;
                    if(dCount <= 0) {
                        return "Radiant";
                    }
                    auto it = dIdx.lower_bound(i);
                    if(it == dIdx.end()) {
                        it = dIdx.begin();
                    }
                    dIdx.erase(it);
                } else if(senate[i] == 'D' && dIdx.count(i) > 0) {
                    rCount--;
                    if(rCount <= 0) {
                        return "Dire";
                    }
                    auto it = rIdx.lower_bound(i);
                    if(it == rIdx.end()) {
                        it = rIdx.begin();
                    }
                    rIdx.erase(it);
                }
            }
        }
        if(rCount <= 0) {
            return "Dire";
        } else {
            return "Radiant";
        }
    }
};