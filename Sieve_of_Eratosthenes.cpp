#include <bits/stdc++.h>
#define ll long long
#define lop1(i,j,n) for(ll i=j; i<n; ++i)
using namespace std;

void solve()
{
    ll n;
    cin>>n;
    vector<bool> is_prime(n+1, true);
    is_prime[0]=is_prime[1]=false;
    for(ll i=2; i*i<=n; ++i)
    {
        if(is_prime[i]) for(ll j=i*i; j<=n; j+=i) is_prime[j]=false;
    }
    lop1(i,0,n+1) cout<<i<<": "<<is_prime[i]<<"\n";
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
