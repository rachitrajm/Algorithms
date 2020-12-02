// Nth Fibonacci Number for large constraints like n<=10^18

#include <bits/stdc++.h>
#define ll long long
const ll M=1e9+7;
using namespace std;

map<ll,ll> m;
ll f(ll n)
{
    if(m.count(n)) return m[n];
    ll k=n/2;
    if(n%2==0) return m[n]=(f(k)*f(k) + f(k-1)*f(k-1))%M;
    else return m[n]=(f(k)*f(k-1) + f(k)*f(k+1))%M;
}

void solve()
{
    ll n;
    cin>>n;
    m[0]=m[1]=1;
    if(!n)
    {
        cout<<0;
        return;
    }
    cout<<f(n-1);
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
