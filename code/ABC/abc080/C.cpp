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
    int F[n+1][11];
    rep(i, n)rep(j, 10) cin >> F[i][j];
    ll P[n+1][11];
    rep(i, n)rep(j, 11) cin >> P[i][j];

    int ttmp[n+1];
    ll ans = 0;
    for(int bit=1; bit < (1<<10); bit++){
        ll tmp = 0;
        fill(ttmp, ttmp+n, 0);
        rep(i, n)rep(j, 10) if((bit & 1<<j) and F[i][j] == 1) ttmp[i]++;
        rep(i, n) tmp += P[i][ttmp[i]];
        if(ans == 0 and tmp != 0){
            ans = tmp;
        }else{
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}