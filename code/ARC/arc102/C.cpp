#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

// TIPS: 2*10^5は long longでやる
int main() {
    ll n, k;
    cin >> n >> k;
    // TIPS: 奇数かどうか bit演算を利用
    if(k & 1){
        ll ans = n/k;
        cout << ans*ans*ans << endl;
    }else{
        ll ans1 = n/k;
        ll ans2 = (n+k/2)/k;
        cout << ans1*ans1*ans1 + ans2*ans2*ans2 << endl;
    }

    return 0;
}