#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

// DAME:
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int ans = 0;
    int active = 0;
    rep(i, n){
        if(active >= h[i]){
            active = h[i];
        }else{
            ans += h[i] - active;
            active = h[i];
        }
    }

    cout << ans << endl;
    return 0;
}