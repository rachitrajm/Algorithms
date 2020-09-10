#include <bits/stdc++.h>
#define ll long long
const ll M=1e9+7;
using namespace std;

ll binpow(ll a, ll b, ll m)
{
    a%=m;
    ll res=1;
    while(b>0)
    {
        if(b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

void solve()
{
    ll n, a, b;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>a>>b;
        cout<<binpow(a,b,M)<<"\n";
    }
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
