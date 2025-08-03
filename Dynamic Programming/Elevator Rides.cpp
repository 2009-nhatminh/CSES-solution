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
    const int maxn = 23;
    #define debug 0
    #define oo (ll)(1e18)


    ll n , x ;
    ll w[maxn + 3 ] ; 
    ll sum[ ( 1 << 21 ) + 3 ] ;

    // bool dp[21][ (1 << 21 ) + 3 ] ;
    // bool check ( int m ) {
    //     FOR ( j , 1 , n )
    //     FOR ( i , 0 , ( 1 << n ) ) dp[j][i] = 0 ; 
    //     dp[0][0] = 1 ;
    //     FOR ( i , 1 , m ) {
    //         FOR ( odd_mask , 0 , ( 1 << n ) - 1 ) {
    //             if (!dp[i-1][odd_mask]) continue ; 
    //             FOR ( new_mask , 0 , ( 1 << n ) -1  ) {
    //                 if ( sum[new_mask] > x ) continue; 
    //                 if ( odd_mask&new_mask !=0) continue; 
    //                 dp[i][new_mask|odd_mask ] = 1 ;
    //                 bitset < 10 > cc ( new_mask ) , cc1 ( odd_mask ) ; 
    //                 cout << i << ' '  << cc << ' ' << cc1 <<  '\n' ;
    //             }
    //         }
    //     }
    //     return dp[m][( 1 << n )-1] ;
    // }

    void input(){
        cin >> n >> x ;
        FOR ( i , 0 , n-1  ) cin >> w[i] ;
        FOR ( i , 0 , ( 1 << n ) - 1) {
            FOR ( j , 0 , n - 1 ) {
                if ( ( ( i >> j ) & 1) ) {
                    sum[i] += w[j] ; 
                }
            }
        }
    
    }
    pair < int , ll > dp [ 1 << 21 ] ;

    void solve ( ) {
        dp[0] = { 1 , 0 } ;
        FOR ( mask , 1 , ( 1 << n ) - 1 ) {
            dp[mask] = { 23 , 0 } ;
            FOR ( j , 0 , n - 1) {
                if ( ( mask >> j ) & 1 ){
                    int old_mask = mask ^ ( 1 << j ) ;
                    bool ok = ( dp[old_mask].sec + w[j] )  <= x ;

                    dp[mask] = min ( dp[mask] , {dp[old_mask].fir + (int)(!ok) , ok?(dp[old_mask].sec + w[j]):w[j]} ) ;
                }
            }
        }
        cout << dp[ ( 1 << n ) - 1 ].fir << '\n' ;
    }
    // void sub1() {  
    //     int l = 1 , r = n ; 
    //     // 20 key 2^20 = 20 * 1e6 = 2 * 1e7 * log ( 20 ) ;
    //     int ans = n ;

    //     while ( l <= r ) {
    //         int m = ( l + r ) >> 1 ;
    //         if (check(m)) ans = m , r = m -1 ;
    //         else l = m + 1 ;
    //     }
    //     cout << ans ;
    // }
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