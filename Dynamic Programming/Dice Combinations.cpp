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
ll dp[Max_n+3] ;
ll cp (int n ) {
	if ( dp[n] !=0 ) return dp[n];
	ll res = 0 ;
	for (int i = 1 ; i <= 6 ; i ++ ){
		if ( i <= n ){
			dp[n] += cp(n-i);
			dp[n]%=MOD;
		}
	}
	return dp[n]%MOD; 
}
void solve(){
	int n ; cin >> n ;
	dp[0] = 1 ; // với khi gặp chính nó thì xúc sắc sẽ là 0
	cp(n);
	cout << dp[n] << '\n';
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
