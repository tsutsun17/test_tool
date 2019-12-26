#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// ナップサック問題
/*
    items[n+1] : itemの価値と重さ
    dp[n+1][m+1] : i個までの品物を考慮して重さwを超えないようにナップザックにいれる場合の価値の合計の最大値

        dp[i][j] = max(dp[i-1][j-品物iの重さ]+品物iの価値, dp[i-1][j])
*/

int main(){
    int n, w;
    cin >> n >> w;
    vector<int> value(n+1);
    vector<int> weight(n+1);
    rep(i, n) cin >> value[i+1] >> weight[i+1];

    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));

    rep(i, n+1) dp[i][0] = 0;
    rep(i, w+1) dp[0][i] = 0;

    rep(i, n+1)rep(j, w+1){
        if(i==0 or j==0) continue;
        if(j-weight[i] >= 0){
            dp[i][j] = max(dp[i-1][j-weight[i]] + value[i], dp[i-1][j]);
        }else{
            dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}