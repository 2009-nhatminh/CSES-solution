#include <bits/stdc++.h>
using namespace std ; 


#define ll long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first 
#define sec second 
#define piint pair < int , int >
#define FOR( i , a , b ) for (int i = (a) , _b = (b) ; i <= _b ; i ++ )  
#define FORD( i , a , b ) for (ll i = (a) , _b = (b) ; i >= _b ; i -- )  

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
    ll n; cin >> n ;
    if ( (n * ( n + 1 ) / 2 ) % 2 != 0 ) {
        cout << "NO" << '\n' ;
        exit( 0 ) ;
    }
    cout << "YES" << '\n' ;
    vector < int > v_1 , v_2 ;
    ll S = 0 ;
    ll MAX = n * ( n + 1 ) /4 ; 
    // cout << MAX << '\n' ;
    FORD ( i , n , 1 ) {
        if ( S + i <= MAX ){
            S += i ;
            v_1.pb ( i ) ;
        }
        else { 
            v_2.pb ( i ) ;
        }
    }
    // cout << S << '\n' ;
    cout << v_1.size() << '\n' ;
    for (auto v : v_1 ) cout << v << ' ' ;
    
    cout << v_2.size() << '\n' ;
    for (auto v : v_2 ) cout << v << ' ' ;

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