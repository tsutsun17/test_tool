#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAX = 510000;

// DAME: 経路問題
// TIPS: 二項係数 nCr   http://drken1215.hatenablog.com/entry/2018/06/08/210000
// TIPS: Mod
/* 
    座標(H-A-1, B+x)までの経路数(左端以外):  C(H-A-1+B+x, B+x) - C(H-A-1+B+x-1, B+x-1)
    *
    そこからゴールまでの経路数: C(A+W-1-B-x, A)

*/

// nCk = (n!) * (k!)^(-1) * ((n-k)!)^(-1)
// fac[a] = a!, finv[a] = 1/(a!), inv[a]: a^(-1) (mod.p)
ll fac[MAX], finv[MAX], inv[MAX];

// 事前処理
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

// 二項計算 nCk
ll COM(int n, int k){
    if(n<k){
        return 0;
    }
    if(n<0 || k<0){
        return 0;
    }
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main(){
    COMinit();
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    ll ans = 0;
    for(int i=0; i<w-b; i++){
        ans = (ans + COM(h-a+b-1+i, b+i) * COM(a+w-b-2-i, a-1)) % MOD;
    }

    cout << ans << endl;
    return 0;
}

// int main() {
//     COMinit();
//     int h, w, a, b;
//     cin >> h >> w >> a >> b;
//     ll ans = 0;
//     ans = COM(h-a+b-1, b) * COM(a+w-b-1, a) % MOD;
//     for(int i=1; i<w-b; i++){
//         ll tmp = (COM(h-a+b-1+i, b+i)-COM(h-a+b-1+i-1, b+i-1)) % MOD;
//         //TIPS: MOD計算でマイナスが出てたら、プラスになるまでMODを足す
//         while(tmp<0){
//             tmp += MOD;
//         }
//         tmp = (tmp * COM(a+w-b-1-i, a)) % MOD;
//         ans = (ans + tmp) % MOD;
//     }

//     cout << ans << endl;
//     return 0;
// }



