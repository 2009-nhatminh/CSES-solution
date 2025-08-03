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
static const int MOD = 1e9 + 7 ;


int n ;
// 500 * 500  
ll dp[250'000 + 3] ;

void isprint ( ){
    ll d = n ;
    if ( d * (d + 1 ) % 4 != 0 ) { cout << 0 ; exit (0) ; }
}
ll mu ( ll a , ll b ){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a % MOD ;
    a %= MOD ;
    ll t = mu ( a , ( b>>1 )); 
    if ( b & 1) return ( ( t * t ) % MOD * a ) % MOD ;
    else return ( t * t ) % MOD ;
}
void input(){
    cin >> n ;
    isprint () ;
    dp[0] = 1 ;
    ll Need = ( n ) * ( n +1 ) / 4 ;
    FOR ( i , 1 , n ) {
        FORD ( j , Need , 0 ){
            if ( j>= i ) 
            dp[j] += dp[j-i] ;
            dp[j] %=MOD ;
        }
    }

    cout << ( dp[Need] *  mu ( 2 , MOD - 2 ) ) % MOD ;
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