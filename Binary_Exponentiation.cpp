#include <bits/stdc++.h>
#define ll long long
const ll M=1e7+7;
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
    ll n=200000000, k=1000000;
    cout<<binpow(n,k,M);
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
