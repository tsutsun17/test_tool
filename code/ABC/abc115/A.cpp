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
    int d;
    cin >> d;
    if(d==25) cout << "Christmas" << endl;
    if(d==24) cout << "Christmas Eve" << endl;
    if(d==23) cout << "Christmas Eve Eve" << endl;
    if(d==22) cout << "Christmas Eve Eve Eve" << endl;
    return 0;
}