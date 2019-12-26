#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

/*
    素因数分解の仕方
        for(ll i=2; pow(i, 2)<= p; i++){
            if(p%i==0){
                int k=0;
                while(p%i==0 && p>0){
                    p/=i;
                    k++;
                }
                // iがk個含まれていることがわかる
            }
        }
*/

// TIPS: 素因数分解
int main() {
    ll n, p;
    cin >> n >> p;

    // 一つだけの場合
    if (n==1) {
        cout << p << endl;
        return 0;
    }

    ll ans = 1;
    // 素因数分解
    for (ll i=2; i*i<=p; i++) {
        if (p%i==0) {
            int k = 0;
            while (p%i==0 && p>0){
                p /= i;
                k++;
            }
            k /= n;
            ans *= pow(i, k);
        }
    }

    cout << ans << endl;

    return 0;
}
