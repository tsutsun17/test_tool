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

int dp[4000][7000];

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> AB(n);
    rep(i, n) cin >> AB[i].first >> AB[i].second;
    sort(AB.begin(), AB.end());
    rep(j, 7000) dp[0][j] = 0;
    dp[1][0] = 0;

    // 配るdp
    /*
        i番目までで時間j以内に食べたものの最高満足度
        配るdpで注文を再現 jで注文したものはj+AB[i-1].firstで食べ終わる
        jをt未満に限定
    */
   int ans = 0;
    rep(i, n+1)rep(j, 7000){
        if(i==0) continue;
        if(j<t){
            dp[i][j+AB[i-1].first] = max(dp[i-1][j+AB[i-1].first], dp[i-1][j] + AB[i-1].second);
        }
        chmax(dp[i][j], dp[i-1][j]);
        if(j!=0){
            chmax(dp[i][j], dp[i][j-1]);
        }
    }
    ans = dp[n][6999];

    cout << ans << endl;
    return 0;
}