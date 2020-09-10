#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string a, b;
    cin>>a>>b;
    ll m=a.size(), n=b.size(), ans=0;
    ll ending=m;
    vector<vector<ll>> c(m+1, vector<ll>(n+1, 0));
    for(int i=1; i<=m; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(a[i-1]==b[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                if(c[i][j]>ans)
                {
                    ans=c[i][j];
                    ending=i;
                }
            }
        }
    }
    cout<<"L_C_Substring: "<<ans<<"\n"<<a.substr(ending-ans,ans);
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
