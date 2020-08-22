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
void solve()
{
    int x1,y1,z1,x2,y2,z2;
    cin>>x1>>y1>>z1;
    cin>>x2>>y2>>z2;
    int ans = 0;
    int temp = min(z1,y2);
    ans+=temp*2;
    z1-=temp;
    y2-=temp;
    temp = min(z1,z2);
    z1-=temp;
    z2-=temp;
    temp = min(z2,x1);
    z2-=temp;
    x1-=temp;
    if(z2>0)
    {
        ans-=2*z2;
    }
    d(ans)
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
