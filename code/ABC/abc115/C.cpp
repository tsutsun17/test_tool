#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end());
    ll ans = 1e9;
    rep(i, n-k+1){
        ll tmp = h[i+k-1]-h[i];
        chmin(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}