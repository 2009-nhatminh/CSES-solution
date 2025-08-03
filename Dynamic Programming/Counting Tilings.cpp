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
const int maxn = 1e3;
#define debug 0
#define oo (ll)(1e18)

const int MOD = 1e9 + 7 ;


int n , m ; 
bool check ( int e_mask ) {
    int d = 0 ;
        // cout << "i" << ' '  << i << '\n' ;
        FOR ( i , 0 , n - 1 ) {
            if ( !(e_mask >> i & 1) ){
                d ++ ;
            }
            else {
                if ( d% 2 != 0 ) return 0 ;
                d = 0 ;
            }
        }
        if ( d% 2 != 0 ) return 0 ;
    return 1 ;
}
ll dp[1003][( 1 << 10 ) +3 ] ; 
ll dfs ( int i , int e_mask ){
    if ( dp[i][e_mask] != -1 ) return dp[i][e_mask] ;
    dp[i][e_mask] = 0 ;
    if ( i == m ) {
        int d = 0 ;
        // cout << "i" << ' '  << i << '\n' ;
        FOR ( l , 0 , n - 1 ) {
            if ( !(e_mask >> l & 1) ){
                d ++ ;
            }
            else {
                if ( d% 2 != 0 ) return dp[i][e_mask] = 0 ;
                d = 0 ;
            }
        }
        if ( d% 2 != 0 ) return dp[i][e_mask] = 0 ;
        return dp[i][e_mask] = 1 ; 
    }
    int mask_upcoming =  0 ;
    ll res = 0 ;
    FOR ( new_mask , 0 , ( 1 << n ) - 1 ) {
        if(debug)
        cerr << "i e n " << i << ' ' << e_mask << ' ' << new_mask << ' ' << (e_mask & new_mask)<< '\n' ;
        if ( !(e_mask & new_mask) ){

            if(debug) 
            cerr << "ok" << '\n' ;
            int mask_need_check = e_mask | new_mask ;
            if (debug)
            cerr << "mask_need_check" << ' ' << mask_need_check << ' ' << check ( mask_need_check ) << '\n' ;
            if (check ( mask_need_check )) {
                mask_upcoming = 0; 
                FOR ( l , 0 , n - 1){
                    if ( new_mask >> l & 1 ) mask_upcoming |= ( 1 << l ) ;
                }
                dfs ( i + 1 , mask_upcoming ) ; 
                res += dp[i+1][mask_upcoming] ;
                // cerr << i+ 1<< ' ' << mask_upcoming << ' ' <<  dp[i+1][mask_upcoming] << '\n' ;
                res %= MOD ;
            }
        }
    }
    return dp[i][e_mask] = res ;  
}

void input(){
    cin >> n >> m ;
    // assert ( check( 3 ) == true ) ;
    if ( n == 1 && m == 1 ) {
        cout << 0 ;
        exit ( 0 ) ;
    }
    FOR ( i, 1 , m ){
        FOR ( j , 0 , ( 1 << n )) 
        dp[i][j] = -1 ;
    }
    ll ans = 0 ;
    dfs ( 1 , 0 )  ;
    
    cout << dp[1][0] ;
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