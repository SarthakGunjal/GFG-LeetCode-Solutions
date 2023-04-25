class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            st.insert(i);
        }
    }
    
    int popSmallest() {
        int i=*st.begin();
        st.erase(st.begin());
        return i;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};