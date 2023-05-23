class KthLargest {
    multiset<int> s;
    int k;
public:
    KthLargest(int K, vector<int>& nums) {
        k = K;
        for(int& n : nums) s.insert(n);
        while (size(s) > k) s.erase(begin(s));
    }
    
    int add(int val) {
        s.insert(val);
        if (size(s) > k) s.erase(begin(s));
        return *begin(s);
    }
};