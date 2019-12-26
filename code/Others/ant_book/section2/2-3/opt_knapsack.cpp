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

/*
    1<=n<=100
    1<=w_i<=1e7
    1<=v_i<=100
    1<=W<=1e9
*/

// dpの対象を入れ替える
int n;
ll W[1000], V[1000], dp[1000][1000];
ll w;


int main(){
    cin >> n;
    rep(i,n) cin >> W[i] >> V[i];
    cin >> w;

    // dp[i][j] := i番目までで、価値の総和がjの時の最小重さ
    // 選べない時はinf
    rep(j, 1002) dp[0][j] = (1<<21);
    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=1001; j++){
            if(j-V[i-1] >= 0){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-V[i-1]] + W[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // wより大きいもののindexを取得し、1をひくとwを超えないvの最大値
    int it = upper_bound(begin(dp[n]), end(dp[n]), w) - begin(dp[n]);

    cout << it - 1 << endl;

    return 0;
}