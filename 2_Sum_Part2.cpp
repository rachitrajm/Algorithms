#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, target;
    cin>>n>>target;
    vector<pair<ll,ll>> a(n);
    for(ll i=0; i<n; ++i)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    int i=0, j=n-1;
    while(i<j)
    {
        if(a[i].first+a[j].first==target)
        {
            cout<<a[i].second<<" "<<a[j].second;
            return;
        }
        else if(a[i].first+a[j].first<target) i++;
        else j--;
    }
    cout<<"IMPOSSIBLE";
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
