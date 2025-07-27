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



ll dp[100003+ 3 ][103]; 
int a[maxn + 3 ] ;

void input(){
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
    int n ; cin >> n ;
    int m ; cin >> m ;

    FOR ( i , 1 , n ) {
        cin >> a[i] ;
    }
    // memset ( dp , -1 , sizeof(dp)) ;
    if ( a[1] == 0 )
    FOR ( i , 1, m )
    dp[1][i] = 1 ;
    else dp[1][a[1]] = 1 ;
    const int MOD = 1e9 + 7 ;
    FOR ( i , 2 , n ) {
        if ( a[i] == 0 ) {
            FOR ( j , 1 , m ) {
                if ( j > 1 ) dp[i][j] += dp[i-1][j-1] ;
                if ( j < m  ) dp[i][j] += dp[i-1][j+1] ;
                dp[i][j] += dp[i-1][j] ;
                dp[i][j] %= MOD ;
            }
        }
        else {
            int j = a[i] ;
            if ( j > 1 ) dp[i][j] += dp[i-1][j-1] ;
                if ( j < m  ) dp[i][j] += dp[i-1][j+1] ;
                dp[i][j] += dp[i-1][j] ;
                dp[i][j] %= MOD ;
        }
        // FOR ( j , 1, m ) {
            // cout << i << ' ' << j << ' ' << dp[i][j] << '\n' ;
        // }
    }
    ll res = 0 ;
    if ( a[n] == 0 ) {
        FOR ( i , 1 , m ) res += dp[n][i] , res %= MOD ;
    }
    else {
        res = dp[n][a[n]] ;
    }
    cout << res ;

    // cout << dp[]
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}