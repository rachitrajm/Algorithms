#include <bits/stdc++.h>
#define ll long long
using namespace std;

void backtrack(vector<vector<bool>> &dp, ll n, ll target, vector<ll> &v)
{
    vector<ll> ans;
    int i=n;
    while(i>0)
    {
        if(dp[i][target]!=dp[i-1][target])
        {
            ans.push_back(v[i-1]);
            target-=v[i-1];
        }
        i--;
    }
    for(auto i: ans) cout<<i<<" ";
    return;
}

void solve()
{
    ll n, target;
    cin>>n>>target;
    vector<ll> v(n);
    for(int i=0; i<n; ++i) cin>>v[i];
    vector<vector<bool>> dp(n+1,vector<bool>(target+1));
    for(int i=0; i<=n; ++i) dp[i][0]=true;
    for(int i=1; i<=target; ++i) dp[0][i]=false;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=target; ++j)
        {
            if(v[i-1]<=j) dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][target])
    {
        cout<<"Subset Found\nValues are: ";
        backtrack(dp,n,target,v);
    }
    else cout<<"No Subset Found\n";
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
