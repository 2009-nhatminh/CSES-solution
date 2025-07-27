#include <bits/stdc++.h>
    #define _nhatminh  int main()
    #define ll long long
    #define str string
    #define fir first
    #define sec second
    #define pb push_back
    #define freopen(name) if(fopen(name".INP","r")) {freopen (name".INP","r",stdin); freopen (name".OUT","w",stdout);}
    #define ALL(x) (x).begin(),(x).end()
    using namespace std;
    int maxx(int n){
        int res=0;
        while (n!=0){
            res=max(res,n%10);
            n/=10;
        }
        return res;
    }
    _nhatminh{
            // 😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎
            freopen("insul");
            ios_base::sync_with_stdio(0);
            cin.tie(0); cout.tie(0);
            int n,dem=0; cin >> n;
            while (n!=0){
                n-=maxx(n);
                cerr  << n << ' ' ;
                dem++;
            }
            cout << dem;
            // 😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎😎
            //ez 20 diem
    return 0;
    }
    /*cc*/
