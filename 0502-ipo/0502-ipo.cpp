class Solution {
public:
    static bool sortbycond(const pair<int,int>& a,const pair<int,int>& b){
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={capital[i],profits[i]};
        }
        sort(v.begin(),v.end(),sortbycond);
        int m=n,j=0;
        priority_queue<int> q;
        while(k>0 && m>0){
            while(j<n && v[j].first<=w){
                q.push(v[j].second);
                j++;
            }
            if(q.empty()){
                break;
            }
            int x=q.top();
            q.pop();
            w+=x;
            k--,m--;
        }
        return w;
    }
};