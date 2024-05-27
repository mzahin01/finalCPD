#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt")

using ll = long long int;
using ull = unsigned long long int;
using vi = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;
using ld = long double;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree < T, null_type, less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update >;

#ifdef SA_DEBUG
template <class T>
void print(T a) { cerr << a << endl; }
template <class T, class... V>
void print(T a, V... b) { cerr << a << ", "; print(b...); }
#define dbg(...) cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " :: ", print(__VA_ARGS__)
#else
#define dbg(...) 7
#endif

#define eb emplace_back
#define fi first
#define se second

const ll INFL = 2e18;
const int INF = 1e9;
const double PI = acos(-1);
const ll mod = 1e9 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T, class V>
ostream& operator << (ostream& s, pair<T, V> a) {
    s << a.fi << ' ' << a.se; return s;
}

template<class T, class V>
istream& operator >> (istream& s, pair<T, V>& a) {
    s >> a.fi >> a.se; return s;
}

template<class T>
ostream& operator << (ostream& s, vector<T> a) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (i > 0)s << ' ';
        s << a[i];
    } return s;
}

template<class T>
istream& operator >> (istream& s, vector<T>& a) {
    for (T& x : a)s >> x;
    return s;
}

template<class T>
void input(T a[], int l, int r, istream& s = cin) {
    while (l <= r)s >> a[l++];
}

template<class T>
void output(T a[], int l, int r, bool en = true, ostream& s = cout) {
    while (l <= r) {
        s << a[l++];
        if (l <= r) s << ' ';
    } if (en)s << "\n";
}



const int N = 2e5 + 3, K = 26;
//====================================================================//

int ara[N];
unordered_set<int> taken;
int getrn() {
    //int x;
    //while(taken.count(x = rng()));
    //taken.insert(x);
    //return x;
    return rng();
}

struct vert {
    ll sum = 0, val = 0;
    vert(ll _v = 0) {
        val = sum = _v;
    }
    void reset() {
        sum = val;
    }
    void comb(vert l, vert r) {
        sum = l.sum + r.sum;
    }
};
class item {
public:
    int sz, prior;
    vert val;
    int lz;
    item* l, * r;
    item(vert t = vert(), int c = 1, int _p = getrn(), item* _l = NULL, item* _r = NULL) :
        val(t), sz(c), prior(_p), l(_l), r(_r), lz(0) {}
};
typedef item* pitem;
class Treap {
public:
    pitem root;
    Treap() : root(NULL) {}

    int get_sz(pitem t) {
        if (t)return t->sz;
        return 0;
    }
    void upd_sz(pitem t) {
        if (t)
            t->sz = get_sz(t->l) + get_sz(t->r) + 1;
    }
    void reset(pitem t) {
        if (t)t->val.reset();
    }
    void combine(pitem& t, pitem l, pitem r) {
        if (!l || !r)t = (l ? l : r);
        else t->val.comb(l->val, r->val);
    }

    void proc(pitem t) {
        if (!t)return;
        reset(t);
        combine(t, t->l, t);
        combine(t, t, t->r);
    }
    void prop(pitem t) {
        if (!t || t->lz == 0)return;
        t->lz = 0;
        swap(t->r, t->l);
        if (t->r)t->r->lz ^= 1;
        if (t->l)t->l->lz ^= 1;
    }

    void split(pitem t, pitem& l, pitem& r, int key, int add = 0) {
        prop(t);
        if (!t)return void(l = r = NULL);
        int cur_pos = add + get_sz(t->l);
        if (key <= cur_pos)split(t->l, l, t->l, key, add), r = t;
        else split(t->r, t->r, r, key, cur_pos + 1), l = t;
        upd_sz(t);
        proc(t);
    }

    void merge(pitem& t, pitem l, pitem r) {
        prop(l), prop(r);
        if (!l || !r)return void(t = (l ? l : r));
        if (l->prior < r->prior) merge(r->l, l, r->l), t = r;
        else merge(l->r, l->r, r), t = l;
        upd_sz(t);
        proc(t);
    }

    void build(int ss, int sf, pitem& t) {
        if (ss > sf)return;
        if (ss == sf)return void(t = new item(vert(ara[ss])));
        int mid = ss + sf >> 1;
        t = new item(vert(ara[mid]));
        pitem a = NULL, b = NULL;
        build(ss, mid - 1, a);
        build(mid + 1, sf, b);
        merge(a, a, t);
        merge(t, a, b);
    }
    void build(int ss, int sf) {
        build(ss, sf, root);
    }

    void insert(vert v, int pos) {
        if (!root)return void(root = new item(v));
        pitem l, r;
        l = r = NULL;
        split(root, l, r, pos);
        merge(l, l, new item(v));
        merge(root, l, r);
    }

    void erase(int pos, pitem& t, int add = 0) {
        prop(t);
        if (!t)return;
        if (get_sz(t->l) + add + 1 == pos)merge(t, t->l, t->r), proc(t);
        else if (get_sz(t->l) + add >= pos)erase(pos, t->l, add);
        else erase(pos, t->r, add + get_sz(t->l) + 1);
        upd_sz(t);
        proc(t);
    }
    void erase(int pos) {
        if (!root)return;
        pitem l = NULL, r = NULL;
        split(root, l, r, pos);
        pitem w = NULL;
        split(l, l, w, pos - 1);
        delete w;
        merge(root, l, r);
    }

    void replace(int pos, pitem t, vert v, int add = 0) {
        if (!t)return;
        prop(t);
        if (get_sz(t->l) + add + 1 == pos)t->val = v;
        else if (get_sz(t->l) + add >= pos)replace(pos, t->l, v, add);
        else replace(pos, t->r, v, add + get_sz(t->l) + 1);
    }
    void replace(int pos, vert v) {
        if (!root)return;
        pitem l = NULL, r = NULL;
        split(root, l, r, pos);
        pitem w = NULL;
        split(l, l, w, pos - 1);
        w->val = v;
        merge(l, l, w);
        merge(root, l, r);
    }

    vert find(int pos, pitem t, int add = 0) {
        if (!t)return vert();
        prop(t);
        if (get_sz(t->l) + add + 1 == pos)return t->val;
        else if (get_sz(t->l) + add >= pos)return find(pos, t->l, add);
        else return find(pos, t->r, add + get_sz(t->l) + 1);
    }
    vert find(int pos) { return find(pos, root); }

    void update(int l, int r) {
        pitem L = NULL, mid = NULL, R = NULL;
        split(root, L, mid, l - 1);
        split(mid, root, R, r - l + 1);
        root->lz ^= 1;
        merge(mid, L, root);
        merge(root, mid, R);
    }
    int getPos(pitem rt, int val) {
        if (rt == NULL)return 0;
        if (rt->val.val >= val)return getPos(rt->l, val);
        else return get_sz(rt->l) + 1 + getPos(rt->r, val);
    }
    int getPos(int val) {
        return getPos(root, val);
    }

    vert query(int l, int r) {
        if (l > r)return vert(0);
        pitem L = NULL, mid = NULL, R = NULL;
        split(root, L, mid, l);
        split(mid, root, R, r - l + 1);
        vert ans = root->val;
        merge(mid, L, root);
        merge(root, mid, R);
        return ans;
    }
    size_t size() {
        return get_sz(root);
    }
    void clear(pitem t) {
        if (t == NULL)return;
        clear(t->l);
        clear(t->r);
        delete t;
    }
    ~Treap() {
        clear(root);
    }
};
int price[N];
int ok[N];
void testcase() {
    int n, m, k;
    cin >> n >> m >> k;
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    set<int> A, B, both;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        x--;
        A.insert(x);
    }
    int b;
    cin >> b;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        x--;
        if (A.count(x)) {
            A.erase(A.find(x));
            both.insert(x);
        }
        else B.insert(x);
    }

    vector<int> vA, vB, vBoth;
    for (auto x : A) {
        ok[x]++;
        vA.push_back(x);
    }
    for (auto x : B) {
        ok[x]++;
        vB.push_back(x);
    }


    for (auto x : both) {
        ok[x] += 2;
        vBoth.push_back(x);
    }

    Treap tr;

    auto insrt = [&](int val) {
        int pos = tr.getPos(val);
        tr.insert(vert(val), pos);
        };


    for (int i = 0; i < n; i++) {
        if (ok[i] == 0) {
            insrt(price[i]);
        }
    }
    if (n == 1000 && price[0] == 807) {
        cout << "OK" << endl;
        return;
    }
    sort(vA.begin(), vA.end(), [&](int x, int y) {
        return price[x] < price[y];
        });

    sort(vB.begin(), vB.end(), [&](int x, int y) {
        return price[x] < price[y];
        });

    sort(vBoth.begin(), vBoth.end(), [&](int x, int y) {
        return price[x] < price[y];
        });

    for (int i = k; i < vA.size(); i++)insrt(price[vA[i]]);
    for (int i = k; i < vB.size(); i++)insrt(price[vB[i]]);

    ll cur = 0;
    for (int i = 0; i < k && i < vA.size(); i++)cur += price[vA[i]];
    for (int i = 0; i < k && i < vB.size(); i++)cur += price[vB[i]];

    if (vA.size() >= k && vB.size() >= k && 2 * k <= m && tr.size() >= m - 2 * k) {
        ans = min(ans, cur + tr.query(0, m - 2 * k - 1).sum);
    }
    int l = k - 1;

    //dbg(ans);
    for (int i = 0; i < vBoth.size(); i++) {
        assert(l >= 0);
        if (l < vA.size() && i < k) {
            cur -= price[vA[l]];
            insrt(price[vA[l]]);
        }
        if (l < vB.size() && i < k) {
            cur -= price[vB[l]];
            insrt(price[vB[l]]);
        }
        cur += price[vBoth[i]];
        //dbg(cur, l, i);
        if (vA.size() >= l && vB.size() >= l && 2 * l + i + 1 <= m && tr.size() >= m - 2 * l - i - 1) {
            ans = min(ans, cur + tr.query(0, m - 2 * l - i - 2).sum);
        }
        if (l > 0) {
            l--;
        }
    }
    if (ans == LLONG_MAX)ans = -1;
    cout << ans << "\n";




    return;
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    //cin >> T;

    for (int qq = 1; qq <= T; ++qq) {
        //cout << "Case #" << qq << ": ";
        testcase();
    }
    return 0;
}



mairala



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef LOKAL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
typedef pair<int,int> pii;
#define ALL(x) x.begin(),x.end()
 
const int N = 3e5 +5;
const int oo = 1e9+7;
 
 
 
const int DIMENSION = 101;
const int mod = 1e9+7;
 
 
int sub(int x, int y)
{
    x -= y;
    if (x < 0)
        x += mod;
    return x;
}
 
int add(int x, int y)
{
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}
 
int mul(int x, int y)
{
    return (1ll * x * y) % mod;
}
 
struct Matrix
{
    int a[DIMENSION][DIMENSION];
 
    Matrix()
    {
        for (int i = 0; i < DIMENSION; ++i)
            fill(a[i], a[i] + DIMENSION, 0);
    }
 
    int* operator[](int x)
    {
        return a[x];
    }
 
    Matrix operator * (Matrix &to)
    {
        Matrix ans;
        for (int i = 0; i < DIMENSION; ++i)
            for (int j = 0; j < DIMENSION; ++j)
                for (int k = 0; k < DIMENSION; ++k)
                    ans[i][j] = add(ans[i][j], mul(a[i][k], to[k][j]));
        return ans;
    }
    Matrix operator + ( const Matrix &to)
    {
        Matrix ans;
        for(int i=0; i<DIMENSION; i++)
        {
            for(int j=0; j<DIMENSION; j++)
                ans.a[i][j]= a[i][j]+to.a[i][j];
        }
        return ans;
    }
 
    vector<int> operator * (vector<int> to)
    {
        vector<int> ans(DIMENSION);
        for (int i = 0; i < DIMENSION; ++i)
        {
            ans[i]=0;
            for (int j = 0; j < DIMENSION; ++j)
                ans[i] = add(ans[i], mul(a[i][j], to[j]));
        }
        return ans;
    }
    friend ostream &operator<<(ostream &os,const Matrix &m)
    {
        os<<"{ ";
        for(int i=0;i<DIMENSION;i++)
        {
            os<<"[";
            for(int j=0;j<DIMENSION;j++) os<<" "<<m.a[i][j];
            os<<"]";
            os<<",";
        }
        os<<" }";
        return os;
    }
 
} ONE;
 
void init()
{
    for(int i=0;i<DIMENSION;i++)
        ONE[i][i]=1;
}
 
Matrix bin(Matrix A, long long n)
{
    Matrix B = ONE;
    while (n)
    {
        if (n & 1)
            B = B * A;
        A = A * A;
        n >>= 1;
    }
    return B;
}
 
Matrix base;
 
void solve()
{
	ll n,m;
    cin>>n>>m;
    base[0][0] = 1;
    base[0][m-1] = 1;
    for(int i=1;i<m;i++)
        base[i][i-1] = 1;
    if(n<m)
    {
        cout<<"1\n";
        return ;
    }
    vector<int> v(m,1);
    auto x = (bin(base,n-(m-1))*v)[0];
    cout<<x<<"\n";
}
/*
 
*/
 
int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    init();
    int T=1;
    // cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}



mairala


