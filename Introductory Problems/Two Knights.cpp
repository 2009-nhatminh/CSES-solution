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




int a[] = { 0 , 0, 6 , 28 , 96 } ;
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
    // cout << 0 << '\n'; 
    FOR ( i , 1 , n ) {

        if ( i <= 3 ) {
            cout << a[i] << '\n' ;
            continue; 
        }
        ll larg = i * 1ll * 1ll * i ;
        ll ans = ( larg * ( larg - 1 ) / 2 ) - 4 * ( i - 1 ) * ( i - 2 ) ;
        cout << ans << '\n' ;
    }
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}