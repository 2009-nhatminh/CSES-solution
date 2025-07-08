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
const int maxn = 2 * 1e5;
#define debug 0
#define oo (ll)(1e18)


vector < int > G[maxn+3] ;
ll d[maxn+3] ;
int c[maxn+3] ;

ll fir_max[maxn+3], sec_max[maxn+3];
void dfs ( int u , int par ) {

    for (auto v : G[u]){
        if (v == par ) continue;
        dfs ( v,  u) ;
            ll val = d[v] + 1 ;
            // cout << v << ' ' << d[v] << '\n'; 
            if ( val > fir_max[u]) {
                sec_max[u]= fir_max[u]; 
                fir_max[u]= val ;
                c[u] = v ;

            }
            else if ( sec_max[u]< val ){
                sec_max[u]= val ;

            }
            d[u] = max ( d[u] , 1 + d[v] ) ;
    }
}
ll ans[maxn+3] ;

void dfs_2 ( int u , int par , ll pre_val ) { 
    ans[u] = max ( pre_val , fir_max[u] );
    for ( auto v : G[u]){
        if ( v == par ) continue; 
        ll new_val = ( c[u] == v ) ? sec_max[u] : fir_max[u] ;
        dfs_2 ( v , u , max ( pre_val , new_val) + 1 ) ;

    }
}
void input(){
}
void solve() {
    int n ; cin >> n ;
    rep ( i , 1 , n ){
        int u , v ; cin >> u >> v;
        G[u].pb ( v ) ;
        G[v].pb ( u ) ;
    }
    dfs ( 1 , - 1 ) ;
    dfs_2 ( 1 , - 1 , 0) ;

    FOR ( i , 1 , n){
        cout << ans[i] << ' ' ;
    } //ans = max ( ans , fir_max[i] + sec_max[i]) ;
    // cout << ans; 
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