#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    vector<int> aa(3);
    cin >> aa[0] >> aa[1] >> aa[2];
    sort(aa.begin(), aa.end(), greater<int>());

    int ans = aa[0]*10 + aa[1] + aa[2];

    cout << ans << endl;
    return 0;
}