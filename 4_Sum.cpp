#include <bits/stdc++.h>
#define ll long long
#define vp vector<pair<ll,ll>>
#define fi first
#define se second
using namespace std;

void solve()
{
    ll n, target;
    cin>>n>>target;
    vector<ll> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    unordered_map<ll, vp> hash;
    for(int i=0; i<n-1; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            ll val=target-a[i]-a[j];
            if(hash.find(val)!=hash.end())
            {
                for(auto p: hash.find(val)->se)
                {
                    ll x=p.fi, y=p.se;
                    if((x!=i and x!=j) and (y!=i and y!=j))
                    {
                        cout<<"Quadruplet Found, Values are: "<<a[i]<<" "<<a[j]<<" "<<a[x]<<" and "<<a[y]<<"\n";
                        return;
                    }
                }
            }
            hash[a[i]+a[j]].push_back({i,j});
        }
    }
    cout<<"No Quadruplet Found.\n";
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
