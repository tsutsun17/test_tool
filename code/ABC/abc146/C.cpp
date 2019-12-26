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
    ll a, b, x;
    cin >> a >> b >> x;
    // int si;
    // ll left = 0;
    // ll right = (ll)1000000001;
    // ll mid;
    // if(x>=a*1000000000+b*10){
    //     cout << 1000000000 << endl;
    //     return 0;
    // }
    // while(left < right){
    //     mid = (left+right)/2;
    //     int si = log10(mid)+1;
    //     int si1 = log10(mid+1)+1;
    //     if(x>=a*mid + b*si and x<a*(mid+1) + b*si1){
    //         cout << mid << endl;
    //         return 0;
    //     }
    //     if(x>=a*mid + b*si){
    //         left = mid;
    //     }else{
    //         right = mid;
    //     }
    // }

    // 模範解答
    ll l=0, r=1000000001;
    int keta;
    while(r-l > 1){
        ll c = (l+r)/2;
        keta = log10(c) + 1;
        if(a*c + b*keta <= x) l = c; else r = c;
    }

    cout << l << endl;

    return 0;
}