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
ll s[maxn + 3] ;
int a[maxn +3  ] ;

static const int MOD = 1e9 + 7 ;
void update ( int idx , int val ) {
    idx ++ ;
    for (  ; idx <= n ; idx += idx&-idx ) {
        s[idx] += val; 
        s[idx] %= MOD ;
    }
}
ll get ( int id  ) {
    id ++ ;
    ll res = 0;
    for ( ; id >= 1 ;id -= id & - id ) {
        res += s[id] ;
        res %= MOD ;
    }
    return res % MOD ;
}
void input(){
    cin >> n;
    vector < int > res ; 

    FOR ( i , 1 , n ) {
        cin >> a[i];
        res.pb ( a[i] ) ;
    }
    sort ( ALL ( res )) ;
    res.erase ( unique ( ALL ( res )) , res.end()) ;
    ll ans = 0 ;
    FOR ( i , 1 , n ) {
        int id = lower_bound ( ALL ( res ) , a[i] ) - res.begin() ;
        // update ( id , 1 ) ;
        ll new_s = get ( id - 1 ) + 1 ;
        // cout << id << ' ' << new_s << '\n' ;
        ans += new_s;
        ans %= MOD ;

        update ( id , new_s % MOD ) ;
    }
    // cout << get ( res.size() );
    cout <<ans ; 

}
void solve() {

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