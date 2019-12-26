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
    int maxx = 0;
    rep(i, n){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
        chmax(maxx, tmp);
    }
    if(a[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> aa(maxx+2, 0);
    ll ans;
    rep(i, n){
        if(i==0){
            ans = 3;
            aa[0]++;
            continue;
        }
        int tmp = a[i];
        if(aa[tmp] >= 3){
            cout << 0 << endl;
            return 0;
        }
        if(tmp != 0){
            ans = ans *  (aa[tmp-1]-aa[tmp]) % mod;
        }else{
            ans = ans *  (3-aa[tmp]) % mod;
        }
        ans %= mod;
        aa[tmp]++;
    }
    if(ans <= 0){
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}