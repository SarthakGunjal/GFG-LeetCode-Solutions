class Solution {
public:

    bool isTriangle(int a,int b,int c){
        return ((a+b > c) and (a+c>b) and b+c>a);
    }

    int largestPerimeter(vector<int>& v) {
        sort(v.begin(),v.end(),greater<int>());
        int n = v.size();

        for(int i=0;i<=n-3;i++){
            if(isTriangle(v[i],v[i+1],v[i+2]))
            return v[i]+v[i+1]+v[i+2];
        }
        
        return 0;
    }
};