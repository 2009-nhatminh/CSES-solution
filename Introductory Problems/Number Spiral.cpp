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





void input(){
}
ll ans;
void solve(){
    ll x,y; cin >> y >> x;
    ll cc=max(x,y);
        ll dt=cc*cc;
        ll k = (cc)*(cc-1)+1;
        //cout << k << ' ';
        if (x==y){cout << x*x-(x-1) << '\n'; return ;}
        else if (x<y){
            if (!(y&1)) k+=(y-x);
            else k-=(y-x);
        }
        else {
            if (x&1) k+=(x-y);
            else k-=(x-y);
        }
        cout << k ; 
        cout << '\n';
}
#define name "TASK" 
int main(){
    fast 
    if(fopen(name".INP","r")) {
        freopen (name".INP","r",stdin);
        freopen (name".OUT","w",stdout);
    }
    input() ;
    int t ; cin >> t ;
    while ( t -- ) 
    solve() ;
    cerr << "\nTIME: = " << (1.0*clock())/CLOCKS_PER_SEC << '\n';
    return(0) ;
}