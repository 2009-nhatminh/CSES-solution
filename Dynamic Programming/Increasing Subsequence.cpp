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
 
int b[maxn + 3] ;
 
void input(){
    int n ; cin >> n ;
    int m = 0 ;
    FOR ( i ,1  , n ){
         int x ; cin >>x ;
         int id = lower_bound ( b + 1 ,b + m + 1 , x) - b ;
         b[id] = x ;
         m = max ( m , id ) ;
    }
    cout << m ;
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