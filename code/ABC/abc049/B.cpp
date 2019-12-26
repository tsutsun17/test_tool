#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(2*h, vector<char>(w));
    rep(i, h)rep(j, w){
        cin >> c[i*2][j];
    }

    for(int i=1; i<2*h; i += 2){
        rep(j, w){
            c[i][j] = c[i-1][j];
        }
    }

    rep(i, 2*h)rep(j, w){
        cout << c[i][j];
        if(j==w-1) cout << endl;
    }
    return 0;
}