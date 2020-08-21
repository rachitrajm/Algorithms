#include <bits/stdc++.h>
#define ll long long
#define uml unordered_map<ll, ll>
using namespace std;

void solve()
{
    ll n, target;
    cin>>n>>target;
    vector<ll> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    uml hash;
    for(int i=0; i<n; ++i)
    {
        if(hash.find(target-a[i])!=hash.end())
        {
            cout<<"Pair Found, Indices of Values are: "<<hash[target-a[i]]<<" and "<<i<<"\n";
            return;
        }
        hash[a[i]]=i;
    }
    cout<<"No Pair Found.\n";
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
