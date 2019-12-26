#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;

/*
    // TIPS: lower_bound, upper_bound

    lower_bound
        探索したいkey以上のイテレータを返す
    upper_bound
        探索したいkeyより大きいイテレータを返す
*/

int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i,n) cin >> L[i];
    sort(L.begin(), L.end());
    int ans = 0;
    rep(b, n)rep(a, b){
        int ab = L[a]+L[b];
        // TIPS: lower_bound indexの求め方
        int r = lower_bound(L.begin(), L.end(), ab) - L.begin();
        int l = b+1;
        // c = [l, r)
        ans += max(0, r-l);
    }

    cout << ans << endl;

    return 0;
}