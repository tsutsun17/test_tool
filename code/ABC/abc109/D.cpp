#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h)rep(j, w) cin >> a[i][j];

    vector<vector<int>> ans;

    rep(i, h)rep(j, w){
        if(j==w-1){
            if(i!=h-1 and a[i][j]%2){
                a[i][j]--;
                a[i+1][j]++;
                ans.push_back({i+1, j+1, i+2, j+1});
            }
        }else{
            if(a[i][j]%2){
                a[i][j]--;
                a[i][j+1]++;
                ans.push_back({i+1, j+1, i+1, j+2});
            }
        }
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    return 0;
}