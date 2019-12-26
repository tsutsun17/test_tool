#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;
// DAME:
int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n), f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());

    // 二分探索
    /*
        a*fの最大値の下限を二分探索で求める
        上限かどうかは、O(n)で求められる

        ×××××××××××××××○○○○○○○○○○○○○○○○○○○○
    */
    ll l = -1, r=1e12;
    while(l+1<r){
        ll mid = (l+r)/2;
        // mid までの
        bool ok = [&](){
            ll s = 0;
            rep(i, n){
                s += max(0ll, a[i] - mid/f[i]);
            }
            return s<=k;
        }();
        if (ok) r=mid; else l = mid;
    }
    cout << r << endl;

    return 0;
}