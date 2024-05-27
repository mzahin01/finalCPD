#include<bits/stdc++.h>
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define f(a,n) for(long long i=a;i<n;i++)
#define f1(n,a) for(long long i=0;i<n;i++)cin>>a[i];
#define f2(n,a) for(long long i=0;i<n;i++)cout<<a[i]<<'\n';
#define s(n,a,d) (n/2.0)*(2*a+(n-1)*d)
typedef long long ll;
using namespace std;
#include<bits/stdc++.h>


using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const long long m = 1000000007;
using ll = long long;
using ull = unsigned long long;
using lld = long double;


#define ll long long
#define mp make_pair
#define pb push_back
#define sc second
#define fr first
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define scs(ch) scanf("%s", ch)
#define pll pair< ll,ll >
#define MX_BIT 29



#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define fro(m) for(int i=1; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define pf push_front
#define orr ||
#define nl '\n'
#define nll cout<<'\n'
#define mod 1000000007
#define inf (1LL<<61)
#define inff (1<<30)
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mxn changeit


#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define pb              push_back
#define xx              first
#define yy              second
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case #"<<tc<<": "
#define nl              cout<<"\n";
#define pi              acos(-1)
#define mod             1000000007
#define inf             1000000000000000001
#define maxn            200001


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set.find_by_order(k) returns the iterator to kth element
// ordered_set.order_of_key(k) returns the number of elements strictly less than k */
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define fastio ios_base::sync_with_stdio(0)
#define flush_off cin.tie(0)
#define mod 1000000007
#define ganja 998244353
#define int ll


#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define powr(x,n,p) for(int axy=0 ; axy<p ; axy++){x=x*n;}
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define nl cout<<"\n"
#define fr0(n,q) for(q=0 ; q<n ; q++)
#define fr1(n,q) for(q=1 ; q<=n ; q++)
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define lst(x) x[x.size()-1]
#define llst(x) x[x.size()-2]
#define md 1000000007
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=(x|(1LL<<y))
#define off(x,y) x=(x&(~(1LL<<y)))
#define pi acos(-1)
#define inf (1LL<<50)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL)
#define pi acos(-1)
#define N  200005 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3*/


#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>   using orderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pi acos(-1)
#define pb push_back
#define pf push_front
#define el "\n"
#define pr pair<ll , ll>
#define ff first
#define ss second
#define pc(x) cout << "Case " << x << ":" <<  " ";
#define valid(x , y , i , j) (i >= 0 && i < x && j >= 0 && j < y)
#define M9 998244353
#define M1 1e9+7


#define clearbit(x, k) (x & ~((long long)1 << k))
#define checkbit(x, k) (x & ((long long)1 << k))
#define setbit(x, k) (x | ((long long)1LL << k))
#define oo 1e10