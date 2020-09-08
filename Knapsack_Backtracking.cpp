#include <bits/stdc++.h>
#define ll long long
using namespace std;

void backtrack(vector<vector<ll>> &dp, ll n, ll target, vector<ll> &v, vector<ll> &w)
{
    vector<pair<ll,ll>> ans;
    int i=n;
    while(i>0)
    {
        if(dp[i][target]!=dp[i-1][target])
        {
            ans.push_back({w[i-1],v[i-1]});
            target-=w[i-1];
        }
        i--;
    }
    for(auto i: ans) cout<<"Weight: "<<i.first<<"\t Value: "<<i.second<<"\n";
    return;
}

void solve()
{
    ll n, target;
    cin>>n>>target;
    vector<ll> v(n), w(n);
    for(int i=0; i<n; ++i) cin>>v[i];
    for(int i=0; i<n; ++i) cin>>w[i];
    vector<vector<ll>> dp(n+1,vector<ll>(target+1));
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=target; ++j)
        {
            if(!i or !j) dp[i][j]=0;
            else if(w[i-1]<=j) dp[i][j]=max(dp[i-1][j-w[i-1]]+v[i-1], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][target]<<"\n";
    backtrack(dp,n,target,v,w);
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
