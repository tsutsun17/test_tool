#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1001001001;

// DAME:
// TIPS: bitDP
/*
    dp[集合s] = sを全て開けられる鍵の買い方の最小コスト
*/
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int>> key;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        int s = 0;
        for(int j=0; j<b; j++){
            int c;
            cin >> c;
            --c;
            // 1 << 3 → 1000
            s |= 1<<c;
        }
        key.emplace_back(s, a);
    }

    vector<int> dp(1<<n, INF); // 2^n
    dp[0] = 0;
    for(int s=0; s < 1<<n; s++){
        for(int i=0; i<m; i++){
            int t = s | key[i].first;
            int cost = dp[s]+key[i].second;
            dp[t] = min(dp[t], cost);
        }
    }
    int ans = dp.back();
    if(ans == INF){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}