#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 連鎖行列積問題
/*
    n個の行列の連鎖 M_1, M_2,...が与えられた時に、スカラー上さんの回数が最小になるように計算順序を決定する問題

    m[n+1][n+1] := m[i][j]を(M_i...M_j)を計算するためn最小の掛け算の回数
    p[n+1] := M_iがp[i-1]×p[i]の行列

    計算回数
        M_i M_i+1 のとき、 p_{i-1} p{i} p{i+1}
        p[i-1]p[k]p[j] = M_i-1の行数とM_kの列数の行列と  M_kの列数の行を持ちM_jの列数の行列の積での計算回数

    m[i][j] = 0
            = min_i<=k<=j(m[i][k] + m[k][j] + p[i-1]p[k]p[j])


    一般的に、連鎖行列積の最適解は、()()の最小コスト(二つに分解したときの最小コスト)

*/

static const int N = 100;

int main(){
    int n, p[N+1], m[N+1][N+1];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i-1] >> p[i];
    }

    for(int i=1; i<=n; i++) m[i][i] = 0;
    for(int l=2; l<=n; l++){
        for(int i=1; i<=n-l+1; i++){
            int j=i+l-1;
            m[i][j] = (1 << 21);
            for(int k=i; k<=j-1; k++){
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }

    cout << m[1][n] << endl;
    return 0;
}
