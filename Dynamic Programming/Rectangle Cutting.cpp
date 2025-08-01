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



int a , b ;
int dp[503][503] ;

void input(){
    int n , m ;

    cin >> n >> m ;
    FOR ( i , 1 , n ) {
        FOR ( j , 1 , m ) {

            if ( i == j ) { dp[i][j] = 0 ; continue ; }
            else dp[i][j] = 1e9 ;

            FOR ( k , 1 , i / 2 ) {
                dp[i][j] = min ( dp[k][j] + dp[i-k][j] + 1 , dp[i][j] ) ;
            }
            FOR ( k , 1 , j / 2 ) {
                dp[i][j] = min ( dp[i][j-k] + dp[i][k] + 1 , dp[i][j] ) ;
            }
        }
    }
    cout << dp[n][m] ;
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
