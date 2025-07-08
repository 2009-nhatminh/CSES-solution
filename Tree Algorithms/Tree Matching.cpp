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
// #define (int)

int maxx = 1e9 ;
vector < int > G[maxn+3] ;

ll d[maxn +3  ][3 ];
// 0 la 
void dfs ( int u , int par) {
    d[u][0] = 0 ;
    for (auto v : G[u]) {
        if ( v == par ) continue; 
        dfs( v , u );
        d[u][0] += max ( d[v][0] , d[v][1]) ;
    }
    for (auto v : G[u]){
        if ( v == par ) continue ;
        ll val = 1 + d[v][0] + d[u][0] - max ( d[v][0] , d[v][1] ) ;
        d[u][1] = max ( d[u][1] , val ) ;
    }
    // cout << u << ' ' << d[u][1] << ' ' << d[u][0] << '\n' ;
}

void input(){
    int n ; cin >> n ;
    FOR ( i , 1 , n - 1 ) {
        int u , v ; cin >> u >> v ;
        G[u].pb ( v ) ;
        G[v].pb ( u ) ;
    }
    // memset ( dp , -1e9 , sizeof(dp)) ;

}
void solve() {

    dfs ( 1 , -1 ) ;
    cout << max ( d[1][1] , d[1][0 ] ) << '\n' ;
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