#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

// 最長共通部分列
/*
    文字列X,Yの連続とは限らない共通部分列の最長を求める
    {TCCAGATGG}
    {TCACA}
    の場合は、{TCAA}

    X_nとY_mを考える
    (i) x_n=y_m
        X_n-1とY_m-1のLCSにx_mを連結したものがLCS
    (ii) x_n≠y_m
        X_n-1とY_mのLCS、X_nとY_m-1のLCSの長い方がLCS

    c[m+1][n+1] := c[i][j]をX_iとY_jのLCSの長さとする二次元配列

    c[i][j] = 0                             if(i==0 || j==0)
            = c[i-1][j-1]+1                 if(i, j > 0 and x_i == y_j)
            = max(c[i-1][j], c[i][j-1])     if(i, j > 0 and x_i ≠ y_j)
*/

static const int N = 1000;

int lcs(string X, string Y){
    int c[N+1][N+1];
    int m = X.size();
    int n = Y.size();
    int maxl = 0;
    X = ' ' + X;    // X[0] に空白を挿入
    Y = ' ' + Y;    // Y[0] に空白を挿入

    for(int i=0; i<=m; i++) c[i][0] = 0;
    for(int j=1; j<=n; j++) c[0][j] = 0;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++){
            if(X[i]==Y[j]){
                c[i][j] = c[i-1][j-1] + 1;
            }else{
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
            maxl = max(maxl, c[i][j]);
        }
    }

    return maxl;
}

int main(){
    string s1, s2;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}