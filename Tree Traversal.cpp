#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define l1 long
#define ld long double
#define lld long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x) cout<<"$ "<<x<<" $"<<endl
#define bug(x) cout<<"& "<<x<<" &"<<endl
#define all(v) v.begin(),v.end()
#define lop1(i,j,n) for(int i=j; i<n; i++)
#define lop2(i,j,n) for(int i=j; i<=n; i++)
#define lop3(i,n,j) for(int i=n; i>j; i--)
#define lop4(i,n,j) for(int i=n; i>=j; i--)
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
const ll MOD=1e9+7;
//int p[N];
//int find(int k){ return p[k]==k ? k : p[k]=find(p[k]); }
using namespace std;

vector<ll>postv, inorv, preov;
struct Node
{
	ll data;
	Node *left, *right;
};
Node* newNode(ll key)
{
	Node* node=new Node;
	node->data=key;
	node->left=node->right=nullptr;
	return node;
}
Node *createTree(ll parent[], ll n)
{
	unordered_map<ll,Node*> map;
	lop1(i,0,n) map[i]=newNode(i);
	Node *root=nullptr;
	lop1(i,0,n)
	{
		if (parent[i]==-1)  root=map[i];
		else
		{
            Node *ptr = map[parent[i]];
            if(ptr->left) ptr->right = map[i];
			else ptr->left=map[i];
		}
	}
	return root;
}
void postorder(struct Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        postv.pub(root->data);
    }
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        inorv.pub(root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        preov.pub(root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void solve()
{
    ll m, ans=0;
    cin>>m;
    ll a[m+1];
    a[0]=-1;
    lop1(i,1,m+1) cin>>a[i];
    Node *root=createTree(a,m+1);
    inorder(root);
    preorder(root);
    postorder(root);
    lop1(i,0,m+1)
    {
        ll z[3];
        z[0]=inorv[i], z[1]=preov[i], z[2]=postv[i];
        sort(z,z+3);
        ans=(ans%MOD+z[1]%MOD)%MOD;
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    fast
    int tc=1;
    cin>>tc;
    while(tc--) solve();
    return 0;
}
