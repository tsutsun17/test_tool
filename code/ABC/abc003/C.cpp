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
    vector<int> r(n);
    rep(i, n) cin >> r[i];
    sort(r.begin(), r.end());
    double ans = 0;
    for(int i=n-k; i<n; i++){
        ans = (double)(ans+r[i])/2;
    }

    cout << setprecision(10) << ans << endl;
    return 0;
}