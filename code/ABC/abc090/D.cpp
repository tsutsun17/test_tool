#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME: arc090D
int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k==0){
        ans = pow(n, 2);
        cout << ans << endl;
        return 0;
    }
    // bを固定する
    for(int i=k+1; i<=n; i++){
        ans += (ll)(i-k)*(n/i);
        if(n%i>=k){
            // 実際に書いて見ればわかる
            ans += n%i - k + 1;
        }
    }

    cout << ans <<endl;

    return 0;
}