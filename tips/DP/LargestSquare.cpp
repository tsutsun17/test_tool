#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 最大正方形
/*
    O(hw)
    dp[i][j] := タイル(i, j)から左上に向かってできる最大の正方形の辺の長さ
    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;

    二次元の累積和的考え方
*/

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(h, vector<int>(w));

    rep(i, h)rep(j, w) cin >> c[i][j];
    vector<vector<int>> dp(h, vector<int>(w, inf));
    rep(i, h)rep(j, w) dp[i][j] = c[i][j] ? 0 : 1;

    int ans = 0;

    rep(i, h)rep(j, w){
        if(i==0 or j==0) continue;
        if(c[i][j]) dp[i][j] = 0;
        else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
        chmax(ans, dp[i][j]);
    }

    cout << ans*ans << endl;
    return 0;
}