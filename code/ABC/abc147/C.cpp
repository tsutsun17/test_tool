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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<P> xy[n];

    rep(i, n){
        cin >> a[i];
        rep(j, a[i]){
            int x, y;
            cin >> x >> y;
            x--;
            xy[i].push_back(make_pair(x, y));
        }
    }
    int ans = 0;
    bool flag = true;
    for(int bit=0; bit<(1<<n); bit++){
        int tmp = 0;
        flag = true;
        rep(i, n){
            if(!flag) break;
            if(bit & (1<<i)){
                tmp++;
                rep(j, a[i]){
                    if(!flag) break;
                    int tmp_x, tmp_y;
                    tmp_x = xy[i][j].first;
                    tmp_y = xy[i][j].second;
                    if(((bit & (1<<tmp_x)) and tmp_y==1) or (!(bit & (1<<tmp_x)) and tmp_y==0)){
                        continue;
                    }else{
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag){
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}