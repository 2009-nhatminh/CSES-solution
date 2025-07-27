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
const int maxn = 1;
#define debug 0
#define oo (ll)(1e18)





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
    input() ;
    solve() ;
    int n ; cin >> n ;
    int x ; cin >> x; 
    vector < ll > a ( n + 1 , 0 ) , dp ( x + 1 , 0 );
    dp[0] = 1; 

    FOR ( i ,1 , n ) cin >> a[i]; 
    const int MOD = 1e9 + 7 ;
    FOR ( i , 0 , x ) {

        FOR ( j ,1 , n ) {
            if ( i - a[j] <  0 ) continue ;  
            if ( dp[i-a[j]] == 0 ) continue;
            
            dp[i] += dp[i-a[j]] % MOD ; 
            dp[i]%=MOD ;
            // cout << dp[i] << ' ' << i << ' ' << i - a[j] << ' ' << dp[i-a[j]]<< '\n' ;
        }
    }
    cout << dp[x] << '\n';
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}
