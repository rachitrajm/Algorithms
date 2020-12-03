#include <bits/stdc++.h>
#define lop1(i,j,n) for(int i=j; i<n; ++i)
using namespace std;

void solve()
{
    int n, max_so_far=INT_MIN, max_ending_here=0;
    cin>>n;
    vector<int> v(n);
    lop1(i,0,n) cin>>v[i];
    lop1(i,0,n)
    {
        max_ending_here=max_ending_here+v[i];
        if(max_so_far<max_ending_here) max_so_far=max_ending_here;
        if(max_ending_here<0) max_ending_here=0;
    }
    cout<<max_so_far;
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
