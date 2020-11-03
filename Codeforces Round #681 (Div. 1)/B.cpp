#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
//#define endl '\n'
#define br cout<<endl
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define d(x) cout<<x<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000000000;
#define maxn 1000005
#define mod 998244353 
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define f(i,n) for(int i=1;i<=n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i+=1)
#define fn(i,k,n) for(int i=k;i>=n;i-=1)
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<endl;}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
int modexp(int x,int y) {
   int res = 1;
   x = x % mod;
   while (y > 0){
       if (y & 1LL)
           res = (res*x) % mod;
       y = y>>1;
       x = (x*x) % mod;  
   }
   return res;
}
int invmod(int a) {
    return modexp(a,mod-2);
}
vector<int> edge[maxn];
void ipgraph(int n,int m) {
    fp(i,1,n) edge[i].clear();
    if(m==0) return;
   fp(i,1,m) {
       int a,b;
       cin>>a>>b;
       edge[a].pb(b);
       edge[b].pb(a);
   } 
}
/*
void dfs(int node,int p)
{
    for(int u : edge[node]) 
    {
        if(u!=p)
        {
            dfs(u,node);
        }
    }
}
*/
///////////////////////////////////////////////////////////////////////////////////
int a[maxn],b[maxn],next1[maxn],prev1[maxn];
map<int,int> ma,mb;
void del(int id)
{
    int prevBlock = prev1[id];
    int nextBlock = next1[id];
    if(prevBlock!=-1)
    {
        next1[prevBlock] = nextBlock;
    }
    if(nextBlock!=-1)
    {
        prev1[nextBlock] = prevBlock;
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    ma.clear();
    mb.clear();
    fp(i,1,n) {cin>>a[i];ma[a[i]] = i;}
    fp(i,1,k) {cin>>b[i];mb[b[i]] = i;}
    fp(i,1,n-1) next1[i] = i+1;
    next1[n] = -1;
    prev1[1] = -1;
    fp(i,2,n) prev1[i] = i-1;
    int ans = 1;
    fp(i,1,k)
    {
        if(ma.find(b[i])==ma.end())
        {
            d(0)
            return ;
        }
        int id = ma[b[i]];
        int prevBlock = prev1[id];
        int nextBlock = next1[id];
        int flag1 = 0,flag2 = 0;
        if(prevBlock==-1) flag1 = 1;
        else if(mb.find(a[prevBlock])!=mb.end()) flag1 = 1;
        if(nextBlock==-1) flag2 = 1;
        else if(mb.find(a[nextBlock])!=mb.end()) flag2 = 1;
        if(flag1&&flag2)
        {
            d(0)
            return ;
        }
        else if(flag2)
        {
            del(prevBlock);
        }
        else
        {
            del(nextBlock);
        }
        if(flag1==0 && flag2==0)
        {
            ans*=2;
            ans%=mod;
        }
        ma.erase(a[id]);
        mb.erase(b[i]);
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
   int t=1;
    cin>>t;
   fp(i,1,t)
   {
       //cout<<"Case #"<<i<<": ";
       solve();
   }
   #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}