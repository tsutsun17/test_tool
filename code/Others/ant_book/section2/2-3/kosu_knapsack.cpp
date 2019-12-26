#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 同じものを何個も選べるknapsack

int n;
int W[1000], V[1000], dp[1000][1000];
int w;


int main(){
    cin >> n;
    rep(i, n) cin >> W[i] >> V[i];
    cin >> w;

    rep(i, n+1) dp[i][0] = 0;
    rep(j, w+1) dp[0][j] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(j >= W[i-1]){
                // dp[i-1][j-W[i-1]] を dp[i][j-W[i-1]] にするだけで個数制限なしのナップサックになる
                dp[i][j] = max(dp[i][j-W[i-1]] + V[i-1], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][w] << endl;

    return 0;
}