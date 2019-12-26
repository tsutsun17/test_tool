#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 10007;

vector<int> a(1e6+1, 0);

int main() {
    int n;
    cin >> n;
    a[2]=1;
    for(int i=3; i<n; i++){
        a[i] = (a[i-1] + a[i-2] + a[i-3]) % mod;
    }

    cout << a[n-1] << endl;

    return 0;
}