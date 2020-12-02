#include <bits/stdc++.h>
#define lop1(i,j,n) for(int i=j; i<n; ++i)
#define pii pair<int,int>
#define pub push_back
#define INF 0x3f3f3f3f
using namespace std;

void solve()
{
    int n, u, v, w, e, src=0;
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
    vector<int> distance(n, INF);
    pq.push({0,src}), distance[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto x: adj[u])
        {
            int v=x.first, w=x.second;
            if(distance[v]>distance[u]+w)
            {
                distance[v]=distance[u]+w;
                pq.push({distance[v],v});
            }
        }
    }
    lop1(i,0,n) cout<<i<<" -> "<<distance[i]<<"\n";
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
