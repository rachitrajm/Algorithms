#include <bits/stdc++.h>
#define lop1(i,j,n) for(int i=j; i<n; ++i)
#define pii pair<int,int>
#define pub push_back
#define INF 0x3f3f3f3f
using namespace std;

void solve()
{
    int n, u, v, w, e, src=0, ans=0;
    cin>>n>>e;
    vector<pii> adj[n];
    lop1(i,0,e)
    {
        cin>>u>>v>>w;
        if(u!=v)
        {
            adj[u].pub({v,w});
            adj[v].pub({u,w});
        }
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(n, INF), parent(n, -1);
    vector<bool> inmst(n, false);
    pq.push({0,src}), key[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        inmst[u]=true;
        for(auto x: adj[u])
        {
            int v=x.first, w=x.second;
            if(inmst[v]==false and key[v]>w)
            {
                key[v]=w;
                pq.push({key[v],v});
                parent[v]=u;
            }
        }
    }
    lop1(i,1,n)
    {
        cout<<parent[i]<<" "<<i<<"\n";
        for(auto x: adj[i]) if(x.first==parent[i]) ans+=x.second;
    }
    cout<<ans;
    return;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t=1;
	//cin>>t;
    while(t--) solve();
	return 0;
}
