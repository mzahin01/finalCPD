#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vpnt(ans)                       \
    for (ll i = 0; i < ans.size(); i++) \
        cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define setbit(x, k) (x |= (1LL << k))
#define clearbit(x, k) (x &= ~(1LL << k))
#define checkbit(x, k) (x & (1LL << k))
#define scl(x) scanf("%lld", &x)
#define sci(x) scanf("%d", &x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define pii pair<int, int>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define yes cout << "yes\n"
#define No cout << "No\n"
#define no cout << "no\n"
#define nn cout << "\n";
#define INF (1 << 30)
#define LL_INF (1LL << 62)
#define pll pair<ll, ll>
#define pp(n, p) (ll)(pow(n, p) + 0.5)
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
// s.order_of_key(3) -> lower bound of 3*/
const ll mod = 998244353;
const ll N = 1e6 + 10;

ll n, a[N], sm[N];
ordered_set<int>s;

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        s.clear();

        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < n; i++)
        {
            int c = s.order_of_key(a[i]);
            sm[i] = c;
            s.insert(a[i]);
        }


        ll ans = 0, mx = INF;
        for (int i = 0; i < n; i++)
        {
            // cout<<i<<": "<<ans<<" "<<mx<<endl;
            if (sm[i] && a[i] < mx)
            {
                ans++;
                mx = min(mx, a[i]);
            }
        }
        cout << ans << endl;
    }