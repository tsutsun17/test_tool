#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1LL<<60;

// DAME:
// TIPS: 図を書いて考える
// 二部グラフの最大マッチングと考えることも可能

/*
    青点のx座標が小さいものからloop
        - 赤点のy座標が高いものを選択
*/

int main(){
    int n, x, y, ans = 0;
    cin >> n;
    vector < pair<ll, ll> > r, b;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        r.push_back({x, y});
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        b.push_back({x, y});
    }
    // 逆向きsort
    sort(r.rbegin(), r.rend());
    sort(b.begin(), b.end());
    
    // bのloop
    for (int i = 0; i < n; i++) {
        ll ymax = -1, pos = -1;
        // rのloop
        for (int j = 0; j < n; j++) {
            if ((r[j].first < b[i].first) && (r[j].second < b[i].second)) {
                if (ymax < r[j].second) {
                    ymax = r[j].second;
                    pos = j;
                }
            }
        }
        if (ymax == -1) continue;
        else {
            // r[pos]を除外
            r[pos].first = inf;
            r[pos].second = inf;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}