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

ll f[maxn+3] ;
int mark[maxn+3] ;
int d[maxn+3] ;
int cnt = 1;
int n , q ;
vector < int > G[maxn+3] ;
ll v[maxn+3] , a[maxn+3] ;
void update ( int idx , ll val ) {
    // idx ++ ;
    while ( idx <= n ) {
        f[idx] += val ;
        idx += ( idx ) & ( -idx ) ;
    }
}
ll get ( int idx ){
    ll res = 0 ;
    while (idx){
        res += f[idx] ;
        idx -= idx & ( - idx ) ;
    } return res ;
}
#define db 0
void reaval_ai ( int i , ll val ) {
    ll compar = val - a[i] ;
    
    a[i] = val ;
    update ( mark[i] , compar ) ;


}
void dfs_make_mark ( int u , int par ){
    mark[u] = cnt ++ ;
    d[u] = 1 ;
    for (auto v : G[u]) {
        
        if ( v == par ) continue; 
        
        dfs_make_mark( v , u ) ;
        d[u] += d[v] ;

    }
}
void input(){
   cin >> n >> q ;

   FOR ( i , 1 , n ) {
        cin >> a[i] ;
   }
   FOR ( i , 2 , n ) {
        int u , v ; cin >> u >> v ;
        G[u].pb (  v ) ;
        G[v].pb (  u ) ;
   }
}
void solve() {
    dfs_make_mark ( 1 , -1 ) ;
    FOR ( i , 1 , n ) {
         update ( mark[i] , a[i] ) ;
    }
    cerr << "sum ALL = " << get ( n ) << '\n' ;
    if (db) {
        FOR ( i , 1 , n ) {
            cout << "m & val" << ' ' << mark[i] << ' ' << a[i] << '\n' ;
        }

    }
    while ( q -- ) {
        int pl ; cin >> pl ;
        if ( pl == 1 ) {
            ll id , val ; cin >> id >> val ;
            reaval_ai ( id , val ) ;
        } 
        else {
            int u ; cin >> u ;
            int fir_id = mark[u] + d[u] - 1 ;
            ll res = get (fir_id ) - get ( mark[u] - 1 ) ;
            if (db) cout << "u - > v" << ' ' << fir_id << ' ' << mark[u] -1 <<  ' ' << d[u] << '\n' ;
            cout << res << '\n' ; 
        }
    }
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