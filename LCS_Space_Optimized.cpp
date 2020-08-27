#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string a, b;
    cin>>a>>b;
    ll m=a.size(), n=b.size();
    if(n>m)
    {
        swap(a,b);
        swap(n,m);
    }
    vector<ll> cur(n+1,0), prev(n+1);
    for(int i=1; i<=m; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(a[i-1]==b[j-1]) cur[j]=prev[j-1]+1;
            else cur[j]=max(prev[j],cur[j-1]);
        }
        prev=cur;
    }
    cout<<"LCS: "<<cur[n]<<"\n";
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
