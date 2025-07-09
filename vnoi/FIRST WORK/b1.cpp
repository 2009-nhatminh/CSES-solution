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


int l , r ;

int n , a[maxn+3] ;
ll s[maxn * 4 + 3  ]; 
void build ( int id , int l , int r ) {
    if ( l ==r ) {
        s[id] = a[l]; 
        return ;
    }
    build ( id * 2 , l , ( l + r ) / 2 ); 
    build ( id * 2 + 1 , ( l + r ) / 2 + 1 , r ) ;
    s[id] = s[id * 2 ] + s[id * 2 + 1] ;

}
ll get (int id , int l , int r , int u , int v ) {
    if ( l > v || r < u ) {
        return 0 ;
    }
    if ( u <= l && r <= v ){
        return s[id] ;
    }
    return get ( id + 2 , l , (l + r ) / 2 , u , v ) + get ( id * 2 + 1 , ( l + r ) / 2 + 1 , r ,u , v ) ;

}
void input(){
    cin >> n >> l >> r ;
    FOR ( i ,1  , n ) cin >> a[i] ;
}
void solve() {
    build ( 1 , 1 , n ) ; 
    ll d = 0 ;
    cout << get ( 1 , 1 , n , 1 , n ) << '\n' ;
    FOR ( i , 1 , n ) {
        int L = i , R = n ;
        int minn_id = -1 ;
        int maxx_id = -1 ;
        while ( L <= R ) {
            int mid = ( L + R ) >> 1ll ;
            ll val = get ( 1 , 1 , n , i , mid ); 
            if ( val >= l ) maxx_id = mid , R = mid - 1 ;
            else L = mid + 1 ;
        }
        L = i , R = n ;

        while ( L <= R ) {
            int mid = ( L + R ) >> 1ll ;
            ll val = get ( 1 , 1 , n , i , mid ); 
            if ( val <= r ) minn_id = mid , L = mid + 1 ;
            else R = mid - 1 ;
        }
        if (minn_id== -1 || maxx_id == -1 ) continue ;
        cerr << maxx_id << ' ' << minn_id << '\n' ;

        d += max ( 0 , maxx_id - minn_id ) ;
    }
    cout << d ;
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