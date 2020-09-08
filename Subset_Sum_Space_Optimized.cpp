#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, target;
    cin>>n>>target;
    vector<ll> v(n);
    for(int i=0; i<n; ++i) cin>>v[i];
    vector<bool> ans(target+1,false);
    ans[0]=true;
    for(int i=0; i<n; ++i) for(int j=target; j>=v[i]; --j) ans[j]=ans[j]||ans[j-v[i]];
    if(ans[target]) cout<<"Subset Found\n";
    else cout<<"No Subset Found\n";
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
