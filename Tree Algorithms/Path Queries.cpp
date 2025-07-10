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



int a[maxn+ 3 ] ;
vector < int > G[maxn +3 ] ;
int n , q ; 
int in[maxn +3 ] , out[maxn +3 ] ;
int cnt = 1 ;
ll f[ ( maxn << 1 )+ 3 ] ;
void dfs ( int u , int par ) {
    in[u] = cnt ++ ;
    for (auto v : G[u]){
        if ( v == par ) continue; 
        dfs ( v , u ) ;
    }
    out[u] = cnt ++ ;

}
int sized = 0 ;

void update ( int i , ll val ) {
    while ( i <= sized ) {
        f[i] += val ;
        i += i & -i ;
    }
}
ll get ( int i ) {
    ll d = 0 ; while ( i > 0 ) { d += f[i] ; i -= i & -i ; } return d ;

}
void input(){
    cin >> n >> q ;
    sized = n * 2 ;
    FOR ( i , 1 , n ) cin >> a[i] ;
    FOR ( i , 2 , n ) {
        int u , v ; cin >> u >> v ;
        G[u].pb ( v ) ;
        G[v].pb ( u ) ;
        // after sufting internet about euler tour , i finally take in this hehe

    }
}
#define db 0
void Minh_le(){
    int pl ; cin >> pl ;
    if ( pl == 1 ) {
        ll i , x ;
        cin >> i >> x ;
        x -= a[i] ;
        a[i] += x ;
        update ( in[i] , x ) ;
        update ( out[i] , -x ) ;  
        return ; 
    }
    int u ;
    cin >> u ;
    if ( db) {
        cout << "range of = " << out[u] -1 << ' ' <<  in[u] << '\n' ;
    }
    cout << get ( out[u] - 1 )  << '\n' ;
}
void solve() {
    dfs ( 1 , -1 ) ;
    FOR ( i , 1 , n ) {
        update ( in[i] , a[i] ) ;
    }
    FOR ( i , 1 , n ) {
        update ( out[i] , -a[i] ) ;
    }
    while ( q -- ) {
        Minh_le () ; 
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