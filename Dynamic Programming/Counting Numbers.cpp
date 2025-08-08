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



str a , b ;
int sized = 0 ;
ll dp[21][2][2]['z'+3 ] ;
ll dfs ( int id , int ok_l , int ok_r , int last ){
    if ( id == sized ) return 1 ;
    if ( dp[id][ok_l][ok_r][last ] != -1 ) return dp[id][ok_l][ok_r][last] ;
    char low = ok_l ? '0' : a[id] ;
    int high= ok_r?'9':b[id] ;
    low = max ( (char)(( id == 0 )? '1' : '0') , low );
    ll res = 0 ;
    FOR ( i , low , high ){

        if ( i == last ) continue ;
        res += dfs ( id + 1 , ok_l | ( i > a[id]) , ok_r | ( i < b[id] ) , i ) ;
        // cout << res << ' ';
    }
    return dp[id][ok_l][ok_r][last] = res; 
}
void input(){
    cin >> a >> b ;
    ll res = 0;
    // str old = a ;
    bool need_plus = 0 ;
    if ( a == "0") need_plus = 1;
    FOR ( len , a.size(), b.size()){
        sized = len ;
        // a = old ;

        memset ( dp , -1 , sizeof ( dp) ) ;
        while ( a.size() < len ) a = "0" + a;
        // cout << dfs ( 0, 0 , 0 , 0 ) ;
        if ( len < b.size() ) res += dfs ( 0 , 0 , 1 , 0 ) ;
        else res += dfs ( 0 , 0 , 0 , 0  ); 
        // cout << dfs ( 0 , 0 , 0 , 0 ) ;
    }
    cout << res + need_plus;
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