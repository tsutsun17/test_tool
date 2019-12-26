#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

// DAME:
int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string ans = "";
    // 1往復目
    ans += string(tx-sx, 'R');
    ans += string(ty-sy, 'U');

    ans += string(tx-sx, 'L');
    ans += string(ty-sy, 'D');

    // ２往復目
    ans += 'D';
    ans += string(tx-sx+1, 'R');
    ans += string(ty-sy+1, 'U');
    ans += 'L';

    ans += 'U';
    ans += string(tx-sx+1, 'L');
    ans += string(ty-sy+1, 'D');
    ans += 'R';

    cout << ans << endl;
    return 0;
}