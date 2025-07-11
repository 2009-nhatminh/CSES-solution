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
const int maxn = 4 * 1e5 ;
#define debug 0
#define oo (ll)(1e18)

int f[maxn+3] ;
int n , t , s ; 
int u[maxn+3] , v[maxn+3] ;

int sized ; 
int find_root ( int u ) {
    return (( f[u] < 0 ) ? u : f[u] = find_root( f[u] ));
}
bool unit ( int x , int y ) {
    x = find_root ( x ) ;
    y = find_root ( y ) ;
    if ( x == y ) return 0 ; 
    if ( f[x] > f[y] ) swap ( x , y ) ;
    f[x] += f[y] ;
    f[y] = x ;
    return 1 ;
}
vector < int > G[maxn+3] ;
bool vt[maxn+3] ;
vector < int > raw_u ; 

int cnt = 0 ;
void tarjan( int u ) {
    vt[u] = 1 ;

    for (auto v : G[u]){
        if (!vt[v]){
            tarjan(v) ;
        }
    }
}
bool check ( int mid ) {
    memset ( vt , 0 , sizeof(vt) ) ;

    rep ( i , 0 , sized ){
        G[i].clear() ;
    }
    FOR ( i , 1 , mid ){
        int sorted_raw_u = lower_bound ( ALL(raw_u) , u[i] ) - raw_u.begin() ; 
        int sorted_raw_v = lower_bound ( ALL(raw_u) , v[i] ) - raw_u.begin() ;
        G[sorted_raw_u].pb(sorted_raw_v) ;
    }
    tarjan ( s ) ;
    if (!vt[t] ) return false ;
    else return true ;
}
void input(){
    cin >> n >> s >> t ;
    FOR ( i , 1 , n ) {
        cin >> u[i] >> v[i] ;
        raw_u.pb ( u[i] ) ;
        raw_u.pb ( v[i] ) ; 
    }
    raw_u.pb ( s ) ;
    raw_u.pb ( t ) ;
    int d = 0 ;
    
    sort ( ALL(raw_u) ) ;
    raw_u.erase(unique( ALL(raw_u) ), raw_u.end()) ;
    memset ( f , -1 , sizeof( f )) ;
    sized = raw_u.size() ;

    s = lower_bound (ALL(raw_u) , s) - raw_u.begin() ; 
    t = lower_bound (ALL(raw_u) , t ) - raw_u.begin() ;
    int l = 1 , r = n ; 
    int ans = 0 ;
    while ( l <= r  ) {
        int mid = ( l + r )>> 1ll ;
        if (check( mid ) ){
            ans = mid ; 
            r = mid - 1 ;
        }
        else l = mid + 1  ;
    }
    cout << ans ; 


}
void solve() {

}
#define name "GRAPH" 
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