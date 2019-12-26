#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

// DAME:
/*
    n, k　を引数として、上から再帰的に求めていく
*/

ll rec(ll n, ll x){
    if(n==0) return 1;
    // n-1の時のバーガーの長さ 2^(n+1) - 3
    ll len = (1LL<<(n+1)) - 3;
    // n-1の時のパティの量 2^(n) - 1
    ll num = (1LL<<n) - 1;
    if(x==1) return 0;

    // 1<x<　バンズ+n-1の時のバーガーの長さ
    if(x<=len+1) return rec(n-1, x-1);
    // x == バンズ+n-1の時のバーガーの長さ+パティ
    if(x==len+2) return num+1;
    // x<= バンズ+n-1の時のバーガーの長さ+パティ+ n-1の時のバーガーの長さ+バンズ
    if(x<=(len+1)*2) return num+1 + rec(n-1, x-len-2);
    // x == nの時のバーガーの長さ
    return num*2+1;
}

int main() {
    ll n, x;
    cin >> n >> x;
    ll ans = rec(n, x);
    cout << ans << endl;
    return 0;
}