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


int n ;
int a[maxn+3] ;
vector < int > G[maxn+3] ;
ll d[maxn+3] ;
void dfs ( int u) {
    d[u] = 1 ;
    for (auto v : G[u]){
        if(!d[v]) dfs(v) ;
        d[u] += d[v] ;
        // cout << u << ' ' << v << ' ' << d[u] << '\n' ;
    }
}
void input(){
    cin >> n ;
    FOR ( i , 2 , n ) cin >> a[i] ;
    
}
void solve() {
    FOR ( i , 2 , n ) {
        int v = i ;
        int u = a[i] ;
        G[u].pb ( v ) ;

    }
    dfs ( 1 ) ;
    FOR ( i , 1 , n ) cout << d[i] - 1 << ' ' ;
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