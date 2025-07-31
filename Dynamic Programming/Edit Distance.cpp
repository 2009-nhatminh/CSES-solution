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


int n ;

str a , b ; 
int m ;
ll dp[5000+3][5003+3] ;
void input(){
    cin >> a >> b ;
}
void solve() {
    n = a.size() ;
    m = b.size() ;
    dp[0][0] = 0 ;
    FOR ( i , 1 , n ) {
        FOR ( j , 1 , m ) {
            if ( dp[0][i] == 0 ) dp[0][i] = i ;
            if ( dp[j][0] == 0 ) dp[j][0] = j ;
            if ( a[i-1] == b[j-1] ) dp[j][i] = dp[j-1][i-1] ;
            else dp[j][i] = 1 + min ( { dp[j-1][i] , dp[j][i-1] , dp[j-1][i-1]} ) ;
        }
    }
    cout << dp[m][n] << '\n' ;
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