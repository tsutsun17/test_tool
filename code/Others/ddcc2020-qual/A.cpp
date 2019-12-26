#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> a = {300000, 200000, 100000};
    vector<int> b = {300000, 200000, 100000};

    x--; y--;
    int ans = 0;
    if(x==0 and y==0){
        ans += 400000;
    }

    cout << ans + a[x] + b[y] << endl;
    return 0;
}