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


int ans = 0 ;
int d[maxn + 3 ] ; 
vector < int > G[maxn + 3]  ;
int n ;
void dfs  (int u , int par ) {
    d[u] = 1 ;
    bool ok = 1 ;

    for (auto v : G[u]){
        if ( v == par ) continue; 
        dfs ( v , u ) ;
        d[u] += d[v] ;
        if (d[v] > n / 2 ) ok = 0 ; 
    }
    if ( n - d[u] > n / 2 ) ok = 0 ;
    if (ok) {
            // ans = u ;
        cout << u ;
        exit ( 0 ) ;
    }
}
#define name "TASK" 
int main(){
    fast 
    if(fopen(name".INP","r")) {
        freopen (name".INP","r",stdin);
        freopen (name".OUT","w",stdout);
    }
    cin >> n ; 
    for ( int i = 2 ; i <= n ; i++ ) {
        int u , v ; cin >> u >> v ;
        G[u].pb ( v ) ;
        G[v].pb ( u ) ;
    }
    dfs ( 1 , -1 ) ;

    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}