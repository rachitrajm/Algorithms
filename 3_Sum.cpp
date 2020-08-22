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
    for(int i=0; i<n; ++i) hash[a[i]]=i;
    for(int i=0; i<n-1; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            int rem=target-a[i]-a[j];
            if(hash.find(rem)!=hash.end() and hash[rem]!=i and hash[rem]!=j)
            {
                cout<<"Triplet Found\n";
                return;
            }
        }
    }
    cout<<"No Triplet Found.\n";
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
