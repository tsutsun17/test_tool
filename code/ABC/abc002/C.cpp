#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

int main() {
    int xa, xb, xc, ya, yb, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    xb -= xa; xc -= xa;
    yb -= ya; yc -= ya;
    double ans = (double)abs(xb*yc - xc*yb)/2;
    cout << setprecision(10) << ans << endl;
    return 0;
}