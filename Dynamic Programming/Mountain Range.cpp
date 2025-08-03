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
 
 
int n ;
int a[maxn + 3 ];
int s[maxn * 4 + 3 ];
int l[maxn +3 ] , r[maxn +3 ] ;
ll dp[maxn + 3 ] ;
int mark[maxn +3  ];
void update ( int id , int l , int r , int pos , int val ) {
    if ( l == r ) {
        s[id] = val;
        return ;
    }
    int m = ( l + r ) >> 1 ;
    if ( pos <= m ) update ( id * 2 , l , m , pos , val ) ;
    else update ( id * 2 + 1 , m + 1 , r , pos , val ) ;
    s[id] = max ( s[id * 2 ] , s[id * 2 + 1 ]) ;
//    while ( id <= n ) s[id] += val ;
}
int get ( int id , int l, int r , int u , int v){
    if ( r < u || l > v ) return 0 ;
    if ( u <= l && r <= v ) return s[id] ;
    int m = ( l + r ) >> 1 ;
    return max ( get ( id *2 , l , m , u , v ) , get ( id * 2 + 1 , m+ 1 , r , u , v)) ;
}
void input(){
    cin >> n ;
    FOR ( i , 1 , n ) {
        cin >> a[i] ;
        mark[i] = i ;
    }
    stack < int > st ;
    FOR ( i , 1 , n ) {
        while ( st.size() && a[i] > a[st.top()]) st.pop() ;
        if (st.size()) l[i] = st.top();
        else l[i] = 0 ;
        st.push ( i ) ;
    }
    st = stack < int > {} ;
    FORD( i , n , 1 ) {
        while ( st.size() && a[i] > a[st.top()]) st.pop() ;
        if (st.size()) r[i] = st.top();
        else r[i] = n+1 ;
        st.push ( i ) ;
    }
    int maxxx = 0 ;
    sort ( mark + 1 , mark + n + 1 , [&] ( int a1 , int b1 ) { return a[a1] < a[b1] ; }) ;
    int i = 1 ;
    while ( i <= n ) {
        int u = mark[i] ;
        int left = l[u] + 1 ;
        int right = r[u] - 1 ;
        int best = 0 ;
        if ( u - 1 >= left ) best = max ( best , get ( 1 , 1 , n , left , u - 1 ) ) ;
        if ( right >= u + 1 ) best = max ( best , get ( 1 , 1 , n , u + 1 , right )) ;
        dp[mark[i]] = best + 1 ;
        maxxx = max ( maxxx , best + 1 );
        update ( 1 , 1 , n , u , dp[u]) ;
        i ++  ;
    }
    cout << maxxx ;
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