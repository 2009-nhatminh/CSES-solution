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
static const int max_log = 20 ;
int up[maxn+3][23] ;
int h[maxn+3] ;
int n , q ;

vector < int > G[maxn+3 ] ;
void dfs ( int u , int par ) {
    
    for (auto v : G[u]) { 
        if ( v == par ) continue ;
        h[v] = h[u] + 1 ;
        up[v][0] =u ; 
        FOR ( j , 1 , max_log ) {
            up[v][j] = up[up[v][j-1]][j-1] ;
        }
        dfs ( v , u ) ;
    }
}

int lca ( int a , int b ){
    if ( h[b] > h[a]) swap ( a , b ) ;
    int k = h[a] - h[b] ;
    FOR ( i , 0 , max_log ) {
        if ( ( k >> i ) & 1 ) {
            a = up[a][i] ;
        }
    } 
    if ( a == b ) return b ;
    FORD( i , max_log , 0){
        if ( up[a][i] != up[b][i]){
            a = up[a][i] ;
            b = up[b][i] ;
        }
    }
    return up[a][0] ;
} 
void input(){
    cin >> n >> q ;
    FOR ( i , 2 , n ) {
        int u ; cin >> u ;
        G[u].pb ( i ) ;
        G[i].pb ( u ) ;
    }
    
    dfs ( 1 , -1 ) ;
    
}
void solve() {
    while ( q -- ) {
        int a , b ; cin >> a>> b ;
        cout << lca ( a , b ) << ' ';
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