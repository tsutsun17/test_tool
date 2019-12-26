#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    rep(i, n) cin >> r[i];
    int maxv = -200000000;
    int minv = r[0];

    rep(i, n){
        if(i==0) continue;
        maxv = max(maxv, r[i] - minv);
        minv = min(minv, r[i]);
    }

    cout << maxv << endl;
    return 0;
}