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
    int n, c;
    cin >> n >> c;
    int D[32][32];
    vector<map<int, int>> C(3);
    rep(i, c)rep(j, c) cin >> D[i][j];
    rep(i, n)rep(j, n){
        int tmp;
        cin >> tmp;
        tmp--;
        C[(i+j)%3][tmp]++;
    }
    vector<vector<int>> abc(3);
    rep(i, 3){
        rep(j, c){
            int tmp=0;
            for(auto itr = C[i].begin(); itr!=C[i].end(); itr++){
                int a = itr->first, count = itr->second;
                tmp += (D[a][j] * count);
            }
            abc[i].push_back(tmp);
        }
    }
    ll ans = INF;
    rep(i, c)rep(j, c)rep(k, c){
        if(i!=j and i!=k and j!=k){
            ll aa = abc[0][i], bb = abc[1][j], cc = abc[2][k];
            chmin(ans, aa+bb+cc);
        }
    }
    cout << ans << endl;

    return 0;
}