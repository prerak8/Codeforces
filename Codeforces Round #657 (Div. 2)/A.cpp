#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){cout<<v.size()<<'\n';  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
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
#define rev(a) reverse(a.begin(),a.en())
const int inf = (int)10e18;
#define maxn 500005
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
int check(string s,int n)
{
    int count = 0;
    fpi(1,n,1)
    {
        if(i+6>n) break;
        if(s.substr(i,7)=="abacaba") count++;
    }
    return count;
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t = "abacaba";
    s = "0" + s;
    fpi(1,n,1)
    {
        string s1 = s;
        if(i+6>n) break;
        fpj(i,i+6,1)
        {
            if(s1[j]=='?') s1[j] = t[j-i];
        }
        fpj(1,n,1) if(s1[j]=='?') s1[j] = 'z';
        if(check(s1,n)==1)
        {
            d("YES")
            d(s1.substr(1))
            return;
        }
    }
    d("NO")
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
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
