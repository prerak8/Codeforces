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
std::vector<pair<int,int>> v,v1;
pair<int,int> ans;
int m;
int checkforzero()
{
    int l = v.size();
    if(v[0].F>0)
    {
        ans = {0,0};
        return 1;
    }
    else if(v[l-1].S<(m/2-1))
    {
        ans = {0,m/2-1};
        return 1;
    }
    int end = v[0].S;
    
    fpi(1,l-1,1)
    {
        if(v[i].F<=end)
        {
            end = max(end,v[i].S);
        }
        else if(v[i].F==end+1)
        {
            end = max(end,v[i].S);
        }
        else
        {
            ans = {0,end+1};
            return 1;
        }
    }
    return 0;
}
void final()
{
    int min = INT_MAX,fans;
    map<int,int> m1;
    int l = v.size();
    fpi(0,l-1,1)
    {
        m1[v[i].F]++;
        m1[v[i].S+1]--;
    }
    map<int, int>::iterator itr;
    int preval = 0;
    for (itr = m1.begin(); itr != m1.end(); ++itr) { 
        itr->S+=preval;
        preval = itr->S;
    }
    for (itr = m1.begin(); itr != m1.end(); ++itr) { 
        int temp = itr->S;
        //d(itr->F<<" "<<itr->S)
        if(itr->F!=m/2)
        {
            if(min>temp)
            {
                min = temp;
                fans = itr->F;
            }
        }
    }
    ans = {min,fans};
}
void solve()
{
    int n,h,k;
    cin>>n>>h>>m>>k;
    pair<int,int> pwd[n+1];
    fpi(1,n,1)
    {
        int a,b;
        cin>>a>>b;
        pwd[i] = {a,b};
        int tot = a*m + b;
        int temp = tot%(m/2);
        int l = temp + 1;
        if(l+k-2>=(m/2))
        {
            v.pb({l,m/2-1});
            v.pb({0LL,(l+k-2)%(m/2)});
        }
        else
        {
            v.pb({l,l+k-2});
        }
    }
    v1 = v;
    sort(v.begin(),v.end());
    int l = v.size();
    //fpi(0,l-1,1) d(v[i].F<<" v "<<v[i].S)
    if(checkforzero())
    {
        d(ans.F<<" "<<ans.S);
    }
    else
    {
        final();
        d(ans.F<<" "<<ans.S);
        fpi(1,n,1)
        {
            int a,b;
            a = pwd[i].F;
            b = pwd[i].S;
            int tot = a*m + b;
            int temp = tot%(m/2);
            int l = temp + 1;
            if(l+k-2>=(m/2))
            {
                if(ans.S>=l && ans.S<=m/2-1)
                {
                    d(i)
                    continue;
                }
                if(ans.S>=0 && ans.S<=(l+k-2)%(m/2))
                {
                    d(i)
                    continue;
                }
            }
            else
            {
                if(ans.S>=l && ans.S<=l+k-2)
                {
                    d(i)
                    continue;
                }
            }
        }
    }
}   
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
