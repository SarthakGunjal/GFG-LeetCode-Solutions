class Solution {
public:
   vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(),
            [](int a, int b) {
                int countA = bitset<32>(a).count();
                int countB = bitset<32>(b).count();
                return (countA == countB) ? (a < b) : (countA < countB);
            });
    return arr;
}
};