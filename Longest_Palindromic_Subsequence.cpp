// This algorithm can also be represented as longest common subsequence of a string and its reversed.
// i.e. LCS(str,reverse(str));
// This gives longest palindromic subsequence of the string.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void backtrack(string a, string b, ll n, vector<vector<ll>> &c)
{
    string result="";
    int i=n, j=n;
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
    cin>>a;
    b=a;
    reverse(b.begin(),b.end());
    ll n=a.size();
    vector<vector<ll>> c(n+1, vector<ll>(n+1));
    for(int i=0; i<=n; ++i) c[0][i]=0;
    for(int i=1; i<=n; ++i) c[i][0]=0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(a[i-1]==b[j-1]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    cout<<"LCS: "<<c[n][n]<<"\n";
    backtrack(a,b,n,c);
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
