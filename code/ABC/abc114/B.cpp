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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 754;
    rep(i, n-2){
        int tmp = (s[i] - '0')*100 + (s[i+1] - '0')*10 + (s[i+2] - '0');
        chmin(ans, abs(tmp-753));
    }

    cout << ans << endl;
    return 0;
}