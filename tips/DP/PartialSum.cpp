#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 最小個数部分和問題

int saisyo_main(){
    int n, A;
    cin >> n >> A;
    vector<int> a(n+1);
    rep(i, n) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(A+1)); // dp[i][j] := i番目までを使ってjを超えないような最小要素数
    rep(i, n+1)rep(j, A+1) dp[i][j] = (1<<21);
    rep(i, n+1) dp[i][0] = 0;

    rep(i, n+1)rep(j, A+1){
        if(i==0 or j==0) continue;
        if(j>=a[i-1]){
            dp[i][j] = min(dp[i-1][j-a[i-1]] + 1, dp[i-1][j]);
        }else{
            dp[i][j] = dp[i-1][j];
        }
    }
    int ans = -1;
    if(dp[n][A] != (1<<21)) ans = dp[n][A];
    cout << ans << endl;
    return 0;
}

// k個以内部分和問題

int k_main(){
    int n, k, A;
    cin >> n >> k >> A;
    vector<int> a(n+1);
    rep(i, n) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(A+1)); // dp[i][j] := i番目までを使ってjを超えないような最小要素数
    rep(i, n+1)rep(j, A+1) dp[i][j] = (1<<21);
    rep(i, n+1) dp[i][0] = 0;

    rep(i, n+1)rep(j, A+1){
        if(i==0 or j==0) continue;
        if(j>=a[i-1]){
            dp[i][j] = min(dp[i-1][j-a[i-1]] + 1, dp[i-1][j]);
        }else{
            dp[i][j] = dp[i-1][j];
        }
    }

    if(dp[n][A] <= k){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }


    return 0;
}