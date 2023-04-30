class dsu
{
    public:
    vector<int>parent;
    vector<int>rank;
    dsu(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int ultimate(int node)
    {
        if(parent[node]==node)
        return node;
        return parent[node]=ultimate(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        u=ultimate(u);
        v=ultimate(v);
        if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else
        {
            parent[u]=v;
            rank[v]++;
        }
    }
};

class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b)
{
    return a[0]>b[0];
}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // for alice 
        dsu a(n+1);
        dsu b(n+1);
        int ans=0;
        sort(edges.begin(),edges.end(),cmp);
        vector<int>visitedA(n+1,0);
        map<vector<int>,int>mp;
        for(auto it:edges)
        {
          int type=it[0];
          int u=it[1];
          int v=it[2];
          if(type!=2  )
          {
              if(a.ultimate(u)!=a.ultimate(v))
              {
                  a.unionbyrank(u,v);
              }
              else
              {
                  mp[it]++;
                  ans++;
              }
          }
        }
        for(int i=1;i<visitedA.size()-1;i++)
        {
            if(a.ultimate(i)!=a.ultimate(i+1))
            return -1;
        }
        
        vector<int>visitedB(n+1,0);
        for(auto it:edges)
        {
          int type=it[0];
          int u=it[1];
          int v=it[2];
          if(type!=1  )
          {
             if(b.ultimate(u)!=b.ultimate(v))
              {
                  b.unionbyrank(u,v);
              }
              else
              {
            if(mp.find(it)==mp.end())
               ans++;
              }
          }
        }
        for(int i=1;i<visitedB.size()-1;i++)
        {
            if(b.ultimate(i)!=b.ultimate(i+1))
            return -1;
        }
        return ans;
    }
};