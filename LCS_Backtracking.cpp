#include <bits/stdc++.h>
#define ll long long
using namespace std;

void backtrack(string a, ll m, string b, ll n, vector<vector<ll>> &c)
{
    string result="";
    int i=m, j=n;
    while(i>0 and j>0)
    {
        if(a[i-1]==b[j-1])
        {
            result+=a[i-1];
            i--, j--;
        }
        else if(c[i-1][j]>c[i][j-1]) i--;
        else j--;
    }
    reverse(result.begin(),result.end());
    cout<<result<<"\n";
    return;
}

void solve()
{
    string a, b;
    cin>>a>>b;
    ll m=a.size(), n=b.size();
    vector<vector<ll>> c(m+1, vector<ll>(n+1));
    for(int i=0; i<=m; ++i)
    {
        for(int j=0; j<=n; ++j)
        {
            if(i==0 or j==0) c[i][j]=0;
            else if(a[i-1]==b[j-1]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    cout<<"LCS: "<<c[m][n]<<"\n";
    backtrack(a,m,b,n,c);
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
