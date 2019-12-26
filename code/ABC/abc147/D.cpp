#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// DAME:
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans  = 0;
    for(ll i = 0; i<60; i++){
        int x = 0;
        int y = 0;
        rep(j, n){
            if(a[j] & (1LL<<i)){
                x++;
            }else{
                y++;
            }
        }
        if(x==n or y==n) continue;
        ll tmp = (1L << i) % mod;
        tmp *= (x % mod);
        tmp %= mod;
        tmp *= (y % mod);
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }

    cout << ans % mod << endl;
    return 0;
}