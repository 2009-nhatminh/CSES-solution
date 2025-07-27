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
const int Max_n=1e5;
ll dp[Max_n+3] ;
struct bookshop
{
    int g , t ; 
};
bookshop a[Max_n+3];
void solve(){
    int n , x ; cin >> n >> x;
    ll res = 0 ; 
    for (int i = 1 ; i <= n ; i ++ )
        cin >> a[i].g;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i].t;
    for (int i = 1 ; i <= n ; i ++ ){
        for (int j = x ; j >= a[i].g ; j -- ){
            dp[j] = max ( dp[j] , dp[j - a[i].g] + a[i].t) ;
            res = max ( res , dp[j]) ;
            //cout << dp[j] << ' ' << j << ' ' << a[i].g << ' ' << a[i].t << '\n';
        }
    }
    cout << res; 
}
#define name "TASK" 
int main(){
    fast 
    if(fopen(name".INP","r")) {
        freopen (name".INP","r",stdin);
        freopen (name".OUT","w",stdout);
    }
    // input() ;
    solve() ;
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}