#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n, m;
    int sum = 0;
    cin >> n;
    vector<int> t(n);
    rep(i, n){
        cin >> t[i];
        sum += t[i];
    }
    cin >> m;
    rep(i, m){
        int p, x;
        cin >> p >> x;
        p--;
        cout << sum - t[p] + x << endl;
    }
    return 0;
}