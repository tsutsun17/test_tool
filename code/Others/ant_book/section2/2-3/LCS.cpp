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

int n, m;
string s, t;

int main(){
    cin >> n >> m >> s >> t;

    int dp[1001][1001]; // dp[i][j] := sのi番目までの文字列とtのj番目までの文字列のLCS

    rep(i, n+1) dp[i][0] = 0;
    rep(j, m+1) dp[0][j] = 0;

    /*
        dp[i][j]
            s_{i} == t_{i} : dp[i-1][j-1]+1 のmax
            s_{i} != t_{i} : dp[i-1][j], dp[i][j-1] のmax

    */

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}