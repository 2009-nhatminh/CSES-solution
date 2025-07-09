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
const int maxn = 2 *1e5 ;
#define debug 0
#define oo (ll)(1e18)
static const int max_log = 20 ;
int n , q , h[maxn+3] , up[maxn+3][23];


vector < int > G[maxn+3] ;
void dfs ( int u , int par = - 1 ){
    for (auto v : G[u]){
        if ( v == par ) continue; 
        up[v][0] = u ;
        h[v] = h[u] + 1 ;
        FOR ( i , 1 , max_log) up[v][i] = up[up[v][i-1]][i-1] ;
        dfs ( v , u ) ;
    }
}
int lca ( int u , int v ) {
    if ( h[u] < h[v]) swap ( u , v) ;
    int k = h[u] - h[v] ;
    FOR ( i , 0 , max_log) {
        if ( ( k >> i ) & 1) {
            u = up[u][i] ; 
        }
    }
    if ( u == v ) return u ;
    FORD ( i , max_log , 0 ) {
        if ( up[u][i] != up[v][i]) {
            u = up[u][i] ;
            v = up[v][i] ;
        }
    }
    return up[u][0] ;

}
void input(){
    cin >> n >> q ;
    FOR ( i ,2 , n ) {
        int u , v ; cin >> u >> v; 
        G[u].pb ( v ) ;
        G[v].pb ( u ) ;
    }
    
}
void solve() {
    dfs ( 1 ) ;
    while ( q -- ) {
        int u , v ; cin >> u >> v ;
        cout << h[u] + h[v] - 2 * h[lca(u,v)] << ' ';
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