#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    // int a[6]={0, 1, 2, 3, 4, 5};

    // if(x<100){
    //     cout << 0 << endl;
    //     return 0;
    // }
    // if(x%100==0){
    //     cout << 1 << endl;
    //     return 0;
    // }
    // int count = x/100;
    // int sita = x-(count*100);

    // rep(i, count+1){
    //     rep(j, count+1-i){
    //         if(count-i-j < 0) break;
    //         rep(k, count+1-i-j){
    //             if(count-i-j-k < 0) break;
    //             rep(h, count+1-i-j-k){
    //                 if(count-i-j-k-h < 0) break;
    //                 rep(l, count+1-i-j-k-h){
    //                     if(count-i-j-k-h-l < 0) break;
    //                     if(sita == i+2*j+3*k+4*h+5*l){
    //                         cout << 1 << endl;
    //                         return 0;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << 0 << endl;

    rep(i, x+1){
        int rest = x-i*100;
        if(0 <= rest and rest <= 5*i){
            puts("1");
            return 0;
        }
        if(rest < 0) break;
    }
    puts("0");
    return 0;
}