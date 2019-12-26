#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;
const ll MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    ll ans = 1;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    if(n%2){
        rep(i, n){
            if(i%2){
                if(a[i] != i+1){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(a[i] != i){
                    cout << 0 << endl;
                    return 0;
                }
            }

        }
    }else{
        rep(i, n){
            if(i%2){
                if(a[i] != i){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(a[i] != i+1){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    rep(j, n/2) ans = (ans*2)%MOD;
    cout << ans << endl;
    return 0;
}