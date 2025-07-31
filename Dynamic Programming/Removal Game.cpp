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
const int maxn = 1e5;
#define debug 0
#define oo (ll)(1e18)



// da doc solve 
// ta goi dp[i][j] la chenh lech giua Player one , Player two .
// xet tai vi tri l r , nguoi choi thu a lay a[l] thi 
// so luong chenh lech giau dp[l][r] = a[l] - dp[l+1][r] 
// nguoc lai neu lay r = a[r] - dp[l][r-1]
// cuoi cung dp[1][n] = player one - two torng turong hop toi uu
// - > sum ALL + dp[1][n] = one * 2

int n ; 
int a[5003 +3  ] ;
ll S = 0 ; 
ll dp[5003][5003] ;
void input(){
    cin >> n ;
    FOR ( i , 1 , n ) cin >> a[i] , S += a[i] ;

}
void solve() {
    FOR ( i , 1 , n ) dp[i][i] = a[i] ;
    // nguoi choi 1 di truoc 
    FOR ( d , 2 , n ) {
        FOR ( l , 1 , n - d + 1  ){
            int r = l + d - 1 ; 
            dp[l][r] = max ( a[l] - dp[l+1][r] , a[r] - dp[l][r-1] ) ;            
        }
    }
    cout << (( S + dp[1][n] )>> 1ll) ;
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