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
const int maxn = 2 *1e5 ;
#define debug 0
#define oo (ll)(1e18)



int n , q ;
int p[maxn+3][23] ;
void input(){
    cin >> n >> q ;
    FOR ( i , 2 , n ) cin >> p[i][0] ;
}
void solve() {
    // lca ;
    static const int max_log = 19 ;

    FOR ( j , 1 , max_log)  
    FOR ( i , 1 , n )    {
        p[i][j] = p[p[i][j-1]][j-1] ;
    }
    // int q;  cin >> q;
    while ( q -- ){
        int u , k ; cin >> u >> k ;
        FOR ( i , 0 , max_log) {
            if ( ( k >> i ) & 1 ) {
                u = p[u][i] ;
            }
        }
        cout << ((!u)?-1:u) << ' ';
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