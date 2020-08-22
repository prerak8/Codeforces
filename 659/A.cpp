#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){cout<<v.size()<<' ';  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
std::vector<int> v[20];
void solve()
{
	fpi(0,19,1) v[i].clear();
	int n;
	cin>>n;
	string a,b;
	cin>>a;
	cin>>b;
	fpi(0,n-1,1)
	{
		if(a[i]>b[i])
		{
			d(-1)
			return ;
		}
		else if(a[i]!=b[i])
		{
			v[a[i]-'a'].pb(i);
		}
	}
	int ans = 0;
	fpi(0,19,1)
	{
		int l = v[i].size();
		if(l==0) continue;
		ans++;
		char mi = 'z';
		fpj(0,l-1,1) mi = min(mi,b[v[i][j]]);
		fpj(0,l-1,1)
		{
			if(b[v[i][j]]!=mi) v[mi-'a'].pb(v[i][j]);
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
	int t=1;
	cin>>t;
	while(t--) solve();
	#ifndef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}
