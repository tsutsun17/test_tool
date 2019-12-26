#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    int min_x, max_x, min_y, max_y;
    min_x = 0; max_x = w; min_y = 0; max_y = h;
    rep(i, n){
        int x, y, a;
        cin >> x >> y >> a;
        if(a==1){
            chmax(min_x, x);
        }else if(a==2){
            chmin(max_x, x);
        }else if(a==3){
            chmax(min_y, y);
        }else if(a==4){
            chmin(max_y, y);
        }
    }
    int hh = max(max_y - min_y, 0);
    int ww = max(max_x - min_x, 0);
    int ans = hh * ww;
    cout << ans << endl;
    return 0;
}