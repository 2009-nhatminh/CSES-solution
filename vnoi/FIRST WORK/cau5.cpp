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
const int maxn = 2 * 1e5 ;
#define debug 0
#define oo (ll)(1e18)



int check[maxn+3] ;

int f[maxn+3] ;
pair < int , int > a[maxn+3] , b[maxn+3] ;
void input(){
}
void solve() {  
    int n ; cin >> n ;
    FOR ( i , 1 , n ) {
        cin >> a[i].fir ;
    }
    FOR ( i , 1 , n ) {
        cin >> a[i].sec ;
    }
    memset( f , 0 , sizeof(f));
    sort ( a + 1 , a + n + 1 ) ;
    int d = 0 ;
    FOR ( i , 1 , n ) {
        int id = lower_bound ( f + 1 , f + d + 1 , a[i].sec )  - f ;
        d = max ( d , id ); 
        f[id] = a[i].sec ;
    }
    cout << d << '\n' ;

}
#define name "cau5" 
int main(){
    fast 
    if(fopen(name".INP","r")) {
        freopen (name".INP","r",stdin);
        freopen (name".OUT","w",stdout);
    }
    input() ;
    int t ; cin >> t ;
    while ( t -- ) { 
        solve() ;
    }
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}
