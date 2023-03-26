class Solution {
public:
int len=0;
int cyc_node=-1;
int dfs(int ind,vector<int>& visited,vector<int>& edges){
    visited[ind]=1;
    if(edges[ind]==-1 || visited[edges[ind]]==2) return 0;
    int x=edges[ind];
    if(visited[x]==1){
        cyc_node=x;
        return 1;
    }
    int ans=dfs(x,visited,edges);
    visited[ind]=2;
    if(ans && ind==cyc_node){
        len=max(len,ans+1);
        ans=0;
        cyc_node=-1;
    }
    return (ans>0)?(ans+1):0;

}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,visited,edges);
                // cout<<len<<" "<<cyc_node<<endl;
            }
        }
        return (len==0)?-1:len;
    }
};