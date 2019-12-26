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

// 重複組み合わせ
/*
    n種類の品物があり、i番目の品物はa_i個ある
    異なる種類の品物同士は区別するが、同じ種類のもの同士は区別しない
    これらの品物の中からm個選ぶ組み合わせの総数を求め、Mで割った余りを求めろ
*/

/*

    dp[i][j] := dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-A[i]]

    dp[i][j-1] := i番目を使う組み合わせの数
    dp[i-1][j] := i番目を使わない組み合わせの数
    dp[i-1][j-1-A[i]] := i番目を使う組み合わせの中で、A[i]回以上i番目を使う組み合わせの数

*/

int n, m, M;
int A[20000];
int dp[2000][2000];     // dp[i][j] := i番目まででj個選ぶ時の組み合わせの総数

int main(){
    cin >> n >> m >> M;
    rep(i, n) cin >> A[i];

    // １つも選ばない方法は１通り
    rep(i, n+1) dp[i][0] = 1;

    rep(i, n+1)rep(j, m+1){
        if(j==0 || i==0) continue;
        if(j-1-A[i-1] >= 0){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-A[i-1]] + M) % M;
        }else{
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % M;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}