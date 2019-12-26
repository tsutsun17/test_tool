#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
// TIPS: bを固定して考える。aを動かさなくても答えがでる。
int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k==0){
        ans = pow(n, 2);
        cout << ans << endl;
        return 0;
    }
    for(int i=k+1; i<=n; i++){
        ans += (ll)(i-k)*(n/i);
        if(n%i >= k){
            ans += n%i-k+1;
        }
    }

    cout << ans << endl;
    return 0;
}