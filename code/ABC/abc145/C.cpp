#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<int> v(n);
    rep(i, n) v[i] = i;
    double ans = 0;
    double count=0;
    do{
        rep(i, n-1){
            double tmp = (x[v[i+1]] - x[v[i]]) * (x[v[i+1]] - x[v[i]]) + (y[v[i+1]]-y[v[i]]) * (y[v[i+1]]-y[v[i]]);
            ans += sqrt(tmp);
        }
        count++;
    }while(next_permutation(v.begin(), v.end()));
    cout << setprecision(16) << ans/count << endl;
    return 0;
}