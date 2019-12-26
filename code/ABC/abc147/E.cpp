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

int h, w;
int a[81][81], b[81][81];
bool dp[81][81][12800];
// DAME:
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;

    rep(i, h)rep(j, w) cin >> a[i][j];
    rep(i, h)rep(j, w) cin >> b[i][j];

    // 途中の段階でもマイナスがめんどくさいため絶対値で考える

    dp[0][0][abs(a[0][0] - b[0][0])] = true;

    rep(i, h)rep(j, w)rep(k, 6400){
        if(dp[i][j][k]){
            int kk = abs(a[i+1][j] - b[i+1][j]);
            int kkk = abs(a[i][j+1] - b[i][j+1]);
            dp[i+1][j][k+kk] = true;
            dp[i+1][j][abs(k-kk)] = true;
            dp[i][j+1][k+kkk] = true;
            dp[i][j+1][abs(k-kkk)] = true;
        }
    }
    rep(i, 6600){
        if(dp[h-1][w-1][i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << 11111 << endl;
    return 0;
}