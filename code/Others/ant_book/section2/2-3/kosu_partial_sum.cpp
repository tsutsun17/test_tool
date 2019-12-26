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
    n種類の数aがそれぞれm個ずつある。
    これらの中からいくつか選び、その総和をちょうどkとすることができるか判定
*/

int n, k;
int A[1000], M[10000];

int main(){
    cin >> n >> k;
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> M[i];

    // dp[i][j] := i番目まででjを作る際に余るi番目の数の最大値(作れない時は-1)
    // dp[i]を用いてdp[i]を更新
    int dp[1000][1000];
    rep(i,n)rep(j,k) dp[i][j] = -1;
    rep(j, k) dp[0][j] = 0;
    rep(i, n)rep(j, k+1){
        if(dp[i-1][j] >= 0){ // i-1番目でjが作れる場合はM[i]
            dp[i][j] = M[i];
        }else if(j-A[i] >= 0 and dp[i][j-A[i]] > 0){ // j >= A[i] かつ i番目まででj-A[i]が作れて、1個以上あまりがある時
            dp[i][j] = dp[i][j-A[i]] - 1;
        }else{ // むり
            dp[i][j] = -1;
        }
    }
    string ans = (dp[n-1][k] > 0) ? "Yes": "No";
    cout << ans << endl;
    return 0;
}

// 配列の再利用
int main(){
    cin >> n >> k;
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> M[i];

    // i番目とi-1番目しか見ない、しかもi-1 -> iの順番
    // だから、1次元にできる
    int dp[100001]; // dp[k]
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    rep(i, n)rep(j, k+1){
        if(dp[j] >= 0){
            dp[j] = M[i];
        }else if(j-A[i] >= 0 and dp[j-A[i]] > 0){
            dp[j] = dp[j-A[i]] - 1;
        }else{
            dp[j] = -1;
        }
    }
    string ans = (dp[k] > 0) ? "Yes": "No";
    cout << ans << endl;
    return 0;
}