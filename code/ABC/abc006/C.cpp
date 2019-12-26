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
    int n, m;
    cin >> n >> m;
    ll s = 4*n-m;
    rep(i, n){
        int a, b, c;
        a = i;
        b = s-2*a;
        c = n-a-b;
        if(a>=0 and b>=0 and c>=0){
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}