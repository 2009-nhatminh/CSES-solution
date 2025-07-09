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
const int maxn = 1e5;
#define debug 0
#define oo (ll)(1e18)


int n , L , R ;
int a[maxn+3] ;
int f[maxn*3+3] ;
ll G[maxn+3] ;
int sized ;
void update ( int id , ll val ){
    id ++ ;
    while ( id < sized) {
        f[id] += val ;
        id += id & -id ;
    }
}
ll get ( int id ){
    id ++ ; 
    ll res = 0 ;
    while ( id > 0 ) {
        res += f[id] ;
        id -= id & -id ;
    }
    return res ;

}
void input(){
    cin >> n >> L >> R ;
    FOR ( i ,1  , n ) cin >> a[i] ;
}
void solve() {
    FOR ( i , 1 , n ) {
        G[i] = G[i-1] + a[i] ;
    }
    vector < ll > raw_G ;
    FOR ( i , 0 , n ) {
        raw_G.pb ( G[i] ) ;
        raw_G.pb ( G[i] - L ) ;
        raw_G.pb ( G[i] - R ) ;
    } 
    sort ( ALL(raw_G) ) ;
    raw_G.erase( unique ( ALL(raw_G)) , raw_G.end()) ;
    vector < ll > sorted_G = raw_G ;
    sized = sorted_G.size() ; 
    ll ans = 0 ;
    FOR ( i , 0 , n ) {
        ll l = G[i] - R ;
        ll r = G[i] - L ; 
        int id_l = lower_bound (ALL ( sorted_G ) , l ) - sorted_G.begin() ;
        int id_r = upper_bound (ALL ( sorted_G ) , r ) - sorted_G.begin() - 1 ;
        if ( id_r < id_l ) continue ;
        ans += get ( id_r ) - get ( id_l - 1 );
        update ( lower_bound (ALL ( sorted_G ) , G[i] ) - sorted_G.begin() , 1 ); 
    }
    cout << ans ; 
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