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
    int n;
    cin >> n;
    int sum = 0;
    int ma = 0;
    rep(i, n){
        int p;
        cin >> p;
        chmax(ma, p);
        sum+=p;
    }

    sum -= ma/2;
    cout << sum << endl;
    return 0;
}