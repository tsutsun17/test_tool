#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i, m) cin >> x[i];

    if(n>=m){
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());

    vector<int> bet(m-1);
    rep(i, m-1){
        bet[i] = x[i+1] - x[i];
    }

    sort(bet.begin(), bet.end());

    int ans = 0;
    rep(i, m-n){
        ans += bet[i];
    }

    cout << ans << endl;

    return 0;
}