#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = pow(10, 9) + 7;

// DAME:
// TIPS: 素因数分解して約数の個数を求める

map<int, int>  divisor;

// 素因数分解
void divide(int n){
    for(int i=2; i<=n; i++){
        if(n%i==0){
            while(n%i==0 && n>0){
                divisor[i]++;
                n /= i;
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    ll ans = 1;
    // 階乗の計算
    for(int j=2; j<=n; j++){
        // それぞれの素因数分解
        divide(j);
    }
    
    for (auto it : divisor) {
        int cnt = it.second;
        ans = ans * (1 + cnt);
        ans %= MOD;
    }

    cout << ans << endl;
    
    return 0;
}