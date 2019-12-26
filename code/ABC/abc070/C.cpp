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

ll gcd(ll x, ll y){
    if(x<y) swap(x, y);
    if(y==0) return x;

    return gcd(y, x%y);
}

ll lcm(ll x, ll y){
    return x/gcd(x, y)*y;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> aa(n);
    rep(i, n) cin >> aa[i];
    sort(aa.begin(), aa.end(), greater<ll>());
    ll ans = aa[0];
    rep(i, n){
        if(i==0) continue;
        ans = lcm(ans, aa[i]);
    }
    cout << ans << endl;
    return 0;
}