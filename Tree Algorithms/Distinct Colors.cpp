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


int n , q ; 
int ans[maxn +3 ] ;
vector < int > G[maxn +3 ] ;
set < int > s[maxn +3 ] ;
int a[maxn +3 ] ;

void dfs ( int u , int par ) {
    s[u].insert ( a[u] ) ;

    for (auto v : G[u]){
        if ( v == par) continue; 
        dfs ( v , u ) ;
        if (s[u].size() < s[v].size()) swap ( s[u] , s[v] ) ;
        for ( auto cnt : s[v]) s[u].insert ( cnt ) ; 
    }
    ans[u] = s[u].size() ;
}
void input(){
    // int n ; 
    cin >> n ;
    FOR ( i , 1 , n ) cin >> a[i] ;
    FOR ( i , 2 , n ) {
        int u , v ; cin >> u >> v ;
        G[u].pb ( v ) ;
        G[v].pb ( u ) ;

    }
}
void solve() {
    dfs ( 1 , -1 ) ;
    FOR ( i , 1 , n )  cout << ans[i] << ' ' ;

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