#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < (int)v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define br cout<<'\n'
#define de(x) cout << (#x) << " : " << (x) << end1l;
#define fni(x,y,z) for(int i=(int)x;i>=(int)y;i-=(int)z)
#define fnj(x,y,z) for(int j=(int)x;j>=(int)y;j-=(int)z)
#define fpi(x,y,z) for(int i=(int)x;i<=(int)y;i+=(int)z)  
#define fpj(x,y,z) for(int j=(int)x;j<=(int)y;j+=(int)z)
#define fpk(x,y,z) for(int k=(int)x;k<=(int)y;k+=(int)z)  
#define fnk(x,y,z) for(int k=(int)x;k>=(int)y;k-=(int)z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end1())
const int inf = (int)10e17;
#define maxn 1000005
const int mod = 1000000007; 
int modexp(int x,int y) 
{ 
    int res = 1;
    x = x % mod; 
    if (x == 0) return 0;
    while (y > 0) 
    {
        if (y & 1LL) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
}
int invmod(int n)
{
    return modexp(n,mod-2);
}
struct line
{
    int l,r,h;
};
std::vector<int> start[maxn],end1[maxn];
line ver[maxn], hor[maxn];
int tree[maxn*4],ma[maxn];
void update(int node, int start, int end1, int idx, int val)
{
    if(start == end1)
    {
        tree[node] += val;
    }
    else
    {
        int mid = (start + end1) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end1, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(int node, int start, int end1, int l, int r)
{
    if(r < start or end1 < l)
    {
        return 0;
    }
    if(l <= start and end1 <= r)
    {
        return tree[node];
    }
    int mid = (start + end1) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end1, l, r);
    return (p1 + p2);
}
bool cc(line a,line b)
{
    return a.h<b.h;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    int ans = 1;
    fpi(1,n,1)
    {
        cin>>hor[i].h>>hor[i].l>>hor[i].r;
        start[hor[i].l].pb(hor[i].h);
        end1[hor[i].r].pb(hor[i].h);
        if(hor[i].r-hor[i].l>=(int)1e6) ans++; 
    }
    fpi(1,m,1)
    {
        cin>>ver[i].h>>ver[i].l>>ver[i].r;
        ma[ver[i].h] = i;
        if(ver[i].r-ver[i].l>=(int)1e6) ans++; 
    }
    // sort(ver+1,ver+m+1,cc);
    fpi(0,1000000,1)
    {
        for(int x:start[i])
        {
            update(1,1,1000000,x,1);
        }
        if(ma[i])
        {
            int id = ma[i];
            ans+=query(1,1,1000000,ver[id].l,ver[id].r);
        }
        for(int x:end1[i])
        {
            update(1,1,1000000,x,-1);
        }
    }
    d(ans)
}   
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    cout<<setprecision(12);
    int t=1;
    //cin>>t;
    for(int i = 1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}