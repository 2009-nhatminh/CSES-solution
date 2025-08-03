#include <bits/stdc++.h>
using namespace std ;
 
 
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define piint pair < int , int >
#define FOR( i , a , b ) for (int i = (a) , _b = (b) ; i <= _b ; i ++ )
#define FORD( i , a , b ) for (int i = (a) , _b = (b) ; i >= _b ; i -- )
 
#define pb push_back
#define str string
#define ALL(a) (a).begin() , (a).end()
#define rep( i , a , b) for (int i = (a) ; i < (b) ; i ++ )
#define ld long double
const int maxn = 2 * 1e5 ;
#define debug 0
#define oo (ll)(1e18)
ll s[maxn * 8 + 3 ];
void update ( int id , int l , int r , int pos , ll val ){
 
    if ( l == r ) {
        s[id] = max ( s[id] , val) ;
        return ;
    }
    int m = ( l + r) >> 1 ;
    if ( pos <= m ) update ( id << 1 , l , m , pos , val ) ;
    else update ( id << 1 | 1 , m + 1 , r , pos , val ) ;
    s[id] = max ( s[id << 1 ] , s[id << 1 |1 ]) ;
 
}
ll get (int id , int l , int r , int u ,int v ){
    if ( l > v || r < u ) return 0 ;
    if ( u <= l && r <= v ) return s[id] ;
    int m = ( l + r ) >> 1;
    return max ( get ( id * 2 , l , m , u , v ) , get ( id * 2 + 1 , m + 1 , r , u , v )) ;
 
}
int n ;
ll dp[maxn + 3 ] ;
struct N{
    int s , e , w ;
};
vector < int > res ;
N a[maxn + 3 ] ;
void input(){
    cin >> n ;
    FOR ( i , 1 , n ){
        cin >> a[i].s >> a[i].e >> a[i].w;
        res.pb ( a[i].e ) ;
        res.pb ( a[i].s ) ;
    }
}
void solve() {
    sort ( a + 1 , a + n + 1 , [&] ( N a , N b ){ return a.e < b.e ; }) ;
    sort ( ALL ( res )) ;
    res.erase ( unique ( ALL ( res)) , res.end()) ;
    int sized = res.size() ;
//    cout << '\n';
//    FOR ( i , 1 , n ) cout << a[i].s << ' ' << a[i].e << ' ' << a[i].w << '\n' ;
//    cout << '\n' ;
//    for (auto v : res) cout << v << ' ' ;
//    cout << '\n' ;
    FOR ( i , 1 , n ) {
        ll best = get ( 1 , 0 , sized  , 0 , lower_bound(ALL ( res ) , a[i].s) - res.begin() - 1 );
        dp[i] = best + a[i].w ;
//        cout << i << ' ' << dp[i] << ' ' << best << ' ' << lower_bound(ALL ( res ) , a[i].s) - res.begin() - 1  << '\n' ;
        update ( 1 , 0 , sized , lower_bound(ALL ( res ) , a[i].e) - res.begin() , dp[i]) ;
//        cout << lower_bound(ALL ( res ) , a[i].e) - res.begin() << '\n' ;
    }
    cout << *max_element ( dp + 1 , dp +n + 1 ) ;
}
#define name "TASK"
int main(){
    fast
    if(fopen(name".INP","r")) {
        freopen (name".INP","r",stdin);
        freopen (name".OUT","w",stdout);
    }
    input() ;
    solve() ;
 
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}