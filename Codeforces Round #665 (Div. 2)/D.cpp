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
#define de(x) cout << (#x) << " : " << (x) << endl;
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
#define rev(a) reverse(a.begin(),a.end())
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
int fans = 0,n;vector<int> path,v[maxn];
int dfs(int node,int p)
{
    int u,i;
    int ans = 1;
    for (i=0;i<(int)v[node].size();i++)
    {
        u=v[node][i];
        if (u!=p)
        {
            ans+=dfs(u,node);
        }
    }
    if(p!=-1)
    {
        path.pb(ans*(n-ans));
    }
    return ans;
}
void solve()
{
    fans = 0;
    path.clear();
    cin>>n;
    fpi(1,n,1) v[i].clear();
    fpi(2,n,1)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,-1);
    int m;
    cin>>m;
    int pri[m+1],cal[n];
    fpi(1,m,1) cin>>pri[i];
    sort(pri+1,pri+m+1,greater<int>());
    if(m<=n-1)
    {
        fpi(1,m,1)
        {
            cal[i] = pri[i];
        }
        fpi(m+1,n-1,1) cal[i] = 1;
    }
    else
    {
        int extra = m - (n-1),cou = 1;
        fpi(extra+1,m,1)
        {
            cal[cou++] = pri[i];
        }
        cal[1]%=mod;
        fpi(1,extra,1)
        {
            cal[1]*=pri[i];
            cal[1]%=mod;
        }
    }
    sort(path.begin(),path.end(),greater<int>());
    fpi(1,n-1,1)
    {
        fans+=((cal[i]%mod)*(path[i-1]%mod))%mod;
        fans%=mod;
    }
    d(fans)
}   
int32_t main()
{
    IOS;
    // #ifndef LOCAL_DEFINE
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout); 
    // #endif
    cout<<setprecision(12);
    int t;
    cin>>t;
    for(int i = 1;i<=t;i++)
    {
        solve();
    }
    // #ifndef LOCAL_DEFINE
    // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
}
