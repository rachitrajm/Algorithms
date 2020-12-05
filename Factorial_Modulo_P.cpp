// Precomputation can be done of factorial vector.

#include <bits/stdc++.h>
#define ll long long
#define lop1(i,j,n) for(ll i=j; i<n; ++i)
using namespace std;

void solve()
{
    ll n, p, res=1;
    cin>>n>>p;
    vector<ll> f(p);
    f[0]=1;
    lop1(i,1,p) f[i]=f[i-1]*i%p;
    while(n>1)
    {
        if((n/p)%2) res=p-res;
        res=res*f[n%p]%p;
        n/=p;
    }
    cout<<res;
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
