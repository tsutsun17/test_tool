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
    int n;
    cin >> n;
    vector<int> a;
    for(int t=1; t<=n; t*=6) a.push_back(t);
    for(int t=9; t<=n; t*=9) a.push_back(t);
    sort(a.begin(), a.end());
    int dp[20][100010];     // dp[i][j] := i番目まで使用して、合計がjになる時の最小の操作数
    int m = a.size();

    rep(i, m+1)rep(j, n+1) dp[i][j] = inf;
    rep(i, m+1) dp[i][0] = 0;
    rep(j, n+1)rep(i, m+1){
        if(i==0) continue;
        dp[i][j] = min(dp[i][j], dp[i-1][j]);
        dp[i][j+a[i-1]] = min(dp[i][j]+1, dp[i-1][j+a[i-1]]);
    }

    cout << dp[m][n] << endl;
    return 0;
}