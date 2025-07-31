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
const int maxn = 1e6;
#define debug 0
#define oo (ll)(1e18)
static const int MOD = 1e9 + 7 ;


ll dp[maxn + 3 ] ;
ll a[maxn + 3] , b[maxn +3] ;

void input(){
}
void solve() {
    
    // while ( n -- ) {
        int x ; cin >> x;
        cout << ( a[x] + b[x]) % MOD << ' ';    
        // }
    }
#define name "Counting Towers" 
int main(){
    fast 
    if(fopen(name".INP","r")) {
        freopen (name".INP","r",stdin);
        freopen (name".OUT","w",stdout);
    }
    a[1] = b[1] = 1 ; 
    FOR ( i , 2 , maxn ) {
        a[i] = 2ll * a[i-1] + b[i-1] ;
        b[i] = 4ll * b[i-1] + a[i-1] ;
        a[i] %= MOD ; 
        b[i] %= MOD ; 
    }
    int q ; cin >>q ;
    while ( q -- ) {
        input() ;
        solve() ;
    }
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}