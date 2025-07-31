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
const int maxn = 3000 ;
#define debug 0
#define oo (ll)(1e18)


int n , m ;
char a[maxn + 3][maxn + 3 ];
int vt[maxn + 3 ][maxn+ 3] ;
void input(){
    cin >> n ;
    m = n ;
    FOR ( i , 1 , n ) {
        FOR ( j , 1 , n ) cin >> a[i][j] ;
    }
}
void solve() {
    vector < piint > current ; 
    str ans = "" ;
    ans.pb ( a[1][1] ) ;
    current.pb ( { 1 , 1 }) ;
    FOR( i , 1 , n * 2 - 2 ) {
        vector < piint > next ;
        int minn = 1e9 ;
        for (auto [ x , y ] : current ){
            if ( x + 1 <= n && !vt[x+1][y] ) {
                minn = min ( minn , (int)a[x + 1 ][y]) ;
                // vt[x+1][y] = 1 ;
            }
            if ( y + 1<= n && !vt[x][y+1]){
                minn = min ( minn , (int)a[x][y + 1 ] ) ;
                // vt[x][y+1] = 1;
            }
        }
        for (auto [ x , y] : current ) {
            if ( x < n ) if ( a[x + 1][y] == minn && !vt[x+1][y]) {
                next.pb ({ x + 1 , y }) ;
                vt[x+1][y] = 1;
            }
            if ( y < n ) if ( a[x][y + 1 ] == minn && !vt[x][y+1]){
                vt[x][y+1] = 1 ;

                next.pb ( { x , y + 1 }) ;
            } 
        }
        ans.pb ( minn ) ;
        current = move ( next ) ;
    }
    cout << ans ;
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