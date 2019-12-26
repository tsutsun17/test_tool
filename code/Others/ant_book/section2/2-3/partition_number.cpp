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
    分割数
        n個の互いに区別できない品物をm個以下に分割する方法の総数
        m=nの時に分割数という
    https://mathtrain.jp/twelveway
*/
int n, m, M;
int dp[1000][1000];     // dp[i][j] := jをi以下に分割した時の総数

/*
    dp[i][j] = dp[i-1][j] + dp[i][j-i]
    dp[i][j] := jをi-1以下に分割した時の総数 + jをi分割した時の総数

    今回は
            - 玉の区別なし
            - 箱の区別なし
            - 少なくとも１つ以上のボールをいれる
*/

// 総数をMで割った余りを求める
int main(){
    cin >> n >> m >> M;
    rep(i, n+1) dp[0][i] = 0;
    dp[0][0] = 1;

    rep(i, m+1)rep(j, n+1){
        if(i==0) continue;
        if(j>=i){
            dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % M;
        }else{
            dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}