#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    切り下げ: a/b
    切り上げ: (a+b-1)/b
    四捨五入: (a+b/2)/b
    二で割る: a>>1
*/
// DAME:
int main() {
    ll n;
    cin >> n;
    ll a=1, b=1;
    for(ll i=0; i<n; i++){
        int tt, aa;
        cin >> tt >> aa;
        // TIPS: 切り上げの方法
        ll tmp = max((a+tt-1)/tt, (b+aa-1)/aa);
        a = tt*tmp;
        b = aa*tmp;
    }

    cout << a+b << endl;
    return 0;
}