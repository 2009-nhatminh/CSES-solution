#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define piint pair<int, int>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)

#define pb push_back
#define str string
#define ALL(a) (a).begin(), (a).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define ld long double
const int maxn = 2 * 1e5;
#define debug 0
#define oo (int)(1e9)

int n, q;
int cnt = 0;

int v[maxn + 3];
int base[maxn + 3]; 
int s[maxn * 4 + 3];
int par[maxn + 3];
int N ;
vector<int> G[maxn + 3];
int d[maxn + 3];
int sz[maxn + 3];
int heavy[maxn + 3], mark[maxn + 3], head[maxn + 3];

void update ( int k ,int x ) {
    k += N ;
    s[k] = x ;
    k >>=1 ;
    while ( k > 1 ) {
        s[k] = max ( s[k << 1 ] , s[k << 1 | 1 ]) ;
        k >>= 1 ;
    }
}

int get (int l , int r ) {
    l += N ;
    r += N ;
    int res = -oo ;
    while ( l <=r ) {
        if ( l & 1 ) res = max ( res , s[l++]) ;
        if (!(r&1)) res = max ( res , s[r--]) ;
        l /= 2 ;
        r /= 2 ;
    }
    return res ;
}

void dfs(int u, int parent) {
    sz[u] = 1;
    int sized = -oo;
    for (auto v : G[u]) {
        if (v == parent) continue;
        par[v] = u;
        d[v] = d[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sized) {
            sized = sz[v];
            heavy[u] = v;
        }
    }
}

void find_head(int u, int h) {
    head[u] = h;
    mark[u] = ++cnt;
    update ( mark[u] , v[u] ) ;

    if (heavy[u]) find_head(heavy[u], h);
    for (auto v : G[u]) {
        if (v == par[u]) continue;
        if (v == heavy[u]) continue;
        find_head(v, v);
    }
}

int find_max(int u, int v) {
    int res = -oo;
    while (head[u] != head[v]) {
        if (d[head[u]] < d[head[v]]) swap(u, v);
        res = max(res, get(mark[head[u]], mark[u]));
        u = par[head[u]];
    }
    if (d[u] > d[v]) swap(u, v);
    res = max(res, get( mark[u], mark[v]));
    return res;
}

void input() {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> v[i];
    }
    N = 1 << (int ) ceil ( log2(n)) ;
    FOR(i, 2, n) {
        int U, V;
        cin >> U >> V;
        G[U].pb(V);
        G[V].pb(U);
    }
}

void solve() {
    d[1] = 1;
    dfs(1, -1);
    find_head(1, 1);

    

    while (q--) {
        int x;
        cin >> x;
        ll u, val;
        cin >> u >> val;
        if (x == 1) {
            update( mark[u], val);
        } else {
            cout << find_max(u, val) << ' ';
        }
    }
}

#define name "TASK"
int main() {
    fast
    if (fopen(name".INP", "r")) {
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }
    input();
    solve();
    cerr << "\nTIME: = " << (1.0 * clock()) / CLOCKS_PER_SEC << '\n';
    return 0;
}
