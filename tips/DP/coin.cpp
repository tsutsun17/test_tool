#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// dp[j] := j円を支払う時のコインの最小枚数

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    rep(i, m) cin >> c[i];
    sort(c.begin(), c.end());
    vector<int> dp(n+1);

    rep(i, n+1) dp[i] = inf;
    dp[0] = 0;

    // 配るDP
    rep(i, m){
        for(int j=0; j+c[i] <= n; j++){
            chmin(dp[j+c[i]], dp[j]+1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}