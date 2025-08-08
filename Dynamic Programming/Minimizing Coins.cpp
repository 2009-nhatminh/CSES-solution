#include <bits/stdc++.h>
#define _nhatminh  int main()
#define ll long long
#define str string
#define fir first
#define sec second
#define ld long double
#define pb push_back
ll MOD = (1e9 + 7);
#define freopen(name) if(fopen(name".INP","r")) {freopen (name".INP","r",stdin); freopen (name".OUT","w",stdout);}
#define ALL(x) (x).begin(),(x).end()
#define piint pair < int , int >
#define piL pair < int , ll>
#define pLL pair < ll , ll >
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
using namespace std;
const int Max_n=1e6;
ll a[Max_n+3] , dp[Max_n+3];
void solve(){
	int n ; cin >> n ;
	ll k ; cin >> k ;
	dp[0] = 0 ;
	for (ll i = 1 ; i <= n; i ++ ) cin >> a[i] ;
	for (ll i = 1; i <= k ; i ++ ){
		dp[i] = 1e18;
		for (ll j = 1; j <= n ; j ++){
			if ( (i - a[j] )>= 0 )
			dp[i] = min ( dp[i] , dp[i - a[j]]  + 1) ;
 		}
 		//cout << dp[i] << ' ';
	}
	if ( dp[k] == 1e18 ) cout << -1;
	else cout << dp[k] ;
}
_nhatminh{
// 😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎
freopen("");
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int q=1;
// cin >> q;
while (q--)
	solve();
cerr << '\n' << "Time elapsed " << TIME << "s.\n";
return (0);
}