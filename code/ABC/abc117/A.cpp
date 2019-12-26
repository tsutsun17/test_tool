#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int t,x;
    cin>>t>>x;
    double ans = (double)t/x;

    cout << setprecision(10) << ans << endl;
    return 0;
}