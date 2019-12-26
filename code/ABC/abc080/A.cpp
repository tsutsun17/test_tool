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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int F[n+1][6][2];
    rep(i, n)rep(j, 10){
        int tmp;
        cin >> tmp;
        F[i][j/2][j%2] = tmp;
    }
    int P[n+1][11];
    rep(i, n)rep(j, 10) cin >> P[i][j];
    ll ans = 0;
    return 0;
}