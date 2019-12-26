#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    rep(i, n){
        cin >> x[i];
    }

    rep(i, m){
        cin >> y[i];
    }

    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end());

    if(x[0] < y[0] and x[0] > X and y[0] <= Y){
        cout << "No War" << endl;
        return 0;
    }

    cout << "War" << endl;
    return 0;
}