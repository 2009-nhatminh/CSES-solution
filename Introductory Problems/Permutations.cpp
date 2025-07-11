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


void input(){
    cin >> n ;
}
void solve() {
    if ( n == 4 ) {
        cout << "3 1 4 2 " ;
        exit ( 0 ) ;
    }
    if ( n == 1) { cout << 1 ; exit (0 ) ;}
    if ( n <= 3 ) {
        cout << "NO SOLUTION" ;
        exit ( 0 ) ;
    }
    for (int i = 1 ; i <= n ; i ++ ) {
        if ( i & 1 ) cout << i << ' ';
    }
    FOR ( i ,1 , n ) {
        if (~i & 1 ) cout << i << ' ';
    }
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