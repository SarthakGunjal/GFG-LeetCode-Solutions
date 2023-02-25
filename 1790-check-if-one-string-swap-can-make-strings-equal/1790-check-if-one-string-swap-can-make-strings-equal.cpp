class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        const auto size = s1.size();
        auto j = -1, k = -1;
        for (auto i = 0; i < size; ++i) {
            if (s1[i] != s2[i]) {
                if (j < 0) j = i;
                else if (k < 0) k = i;
                else return false;
            }
        }
        return j < 0 && k < 0 || j >= 0 && k >= 0 && s1[j] == s2[k] && s2[j] == s1[k];
    }
};