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
    vector<vector<char>> c(4, vector<char>(4));
    rep(i, 4)rep(j, 4) cin >> c[i][j];
    rep(i, 2)rep(j, 4){
        swap(c[i][j], c[3-i][3-j]);
    }

    rep(i, 4){
        rep(j, 4){
            if(j!=0) cout << ' ';
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}