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





void input(){
}
void solve() {

}
bool a[maxn +3 ][maxn +3 ];
ll dp[maxn +3 ][maxn + 3 ];

#define name "TASK" 
int main(){
    fast 
    if(fopen(name".INP","r")) {
        freopen (name".INP","r",stdin);
        freopen (name".OUT","w",stdout);
    }
    input() ;
    solve() ;
    int n , m ; cin >> n ;
    FOR ( i , 1 , n ){
        str s ; cin >> s ;
        rep ( j , 0 , s.size()){
            a[i][j+1] = (s[j]=='*') ? 1 : 0 ;
        }
    }
    dp[1][1] = a[1][1] ^ 1;

    const int MOD = 1e9 + 7 ;
    FOR ( i , 1, n ) {
        FOR ( j , 1 , n ) {
            if ( a[i][j] == 1 ) continue ;
            if ( i > 1 ) if ( a[i-1][j] != 1 ) dp[i][j] += dp[i-1][j] ;
            if ( j > 1 ) if ( a[i][j-1] != 1 ) dp[i][j] += dp[i][j-1] ;
            dp[i][j] %= MOD ;
        }
    }
    cout << dp[n][n] << '\n' ;
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}