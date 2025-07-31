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
const int maxn = 1000 ;
#define debug 0
#define oo (ll)(1e18)



int n, m;
int a[maxn+3], b[maxn+3];
int dp[maxn+3][maxn+3];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
}

void solve() {
    
    FOR ( i , 1 , n ) {
        FOR ( j , 1 , m ) {
            if ( a[i] == b[j] ) dp[i][j] = dp[i-1][j-1] + 1 ;
            else dp[i][j] = max ({dp[i-1][j-1], dp[i-1][j] , dp[i][j-1] }) ;
            // cout << dp[i][j] << ' ' << i << ' ' << j << '\n' ;
        }
    }
    // cout << "cc123" << ' '  << dp[n][m] << '\n' ;
    vector <int> lcs ;
    int i = n , j = m ;
    while ( i >= 1&& j >=1 ) {
        if ( a[i] == b[j]) lcs.pb ( a[i]) , i -- , j -- ;
        else {
            if ( dp[i][j-1] > dp[i-1][j]) j -- ;
            else i -- ;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs.size() << '\n';
    for (int x : lcs) cout << x << ' ';
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