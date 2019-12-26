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

ll ans = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n), ab(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    rep(i, n) ab[i] = 0;

    rep(i, a.size()){
        int index = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        ab[index]++;
    }
    rep(i, n){
        if(i==0) continue;
        ab[i] += ab[i-1];
    }
    rep(i, b.size()){
        int index = upper_bound(c.begin(), c.end(), b[i]) - c.end();
        ans += ab[i] * (index);
    }

    cout << abs(ans) << endl;
    return 0;
}