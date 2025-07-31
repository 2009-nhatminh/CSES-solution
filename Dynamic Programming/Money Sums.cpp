#include <bits/stdc++.h>
using namespace std ; 


#define ll long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first 
#define sec second 
#define piint pair < int , int >
#define FOR( i , a , b ) for (ll i = (a) , _b = (b) ; i <= _b ; i ++ )  
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
int a[maxn + 3] ;
static const int BASE = 1e5 ;
bool dp[100003] ;
void input(){
    cin >> n ;
    FOR ( i , 1 , n )
    cin >> a[i] ;
    sort ( a + 1, a + n + 1 ) ;
}
void solve() {
    dp[0] = 1; 
    FOR ( i , 1 , n ){
    FORD( j , BASE , 0){
            if ( j >= a[i]){
                dp[j] = max ( dp[j] , dp[j-a[i]] ) ;
                // if ( j == 6 ) cout << j-a[i] << ' ' << dp[j-a[i]]<< '\n' ;
            }
            // if ( dp[j - ])
        }
    }

    vector < int > ans ;
    FOR ( j , 1 , BASE ){
        if (dp[j]) ans.pb ( j ); 
        // cout << j << ' '; 
    } cout << ans.size() << ' ' ;
    for (auto v : ans ) cout << v << ' ';
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