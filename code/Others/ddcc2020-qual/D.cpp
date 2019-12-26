#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// DAME:
int main() {
    int m;
    cin >> m;
    vector<ll> d(m), c(m);
    rep(i, m) cin >> d[i] >> c[i];
    ll ans = 0;
    ll sum = 0;
    rep(i, m){
        sum += (d[i] * c[i]);
        ans += c[i];
    }
    ans--;

    ans += (sum-1)/9;
    cout << ans << endl;
    return 0;
}