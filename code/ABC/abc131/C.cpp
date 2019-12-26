#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll c_count=b/c-(a-1)/c, d_count=b/d-(a-1)/d, c_d_count, x=d*c, r;
    //  c < dに統一
    if(c>d){
        swap(c, d);
    }
    r = d%c;
    while(r!=0){
        d = c;
        c = r;
        r = d%c;
    }
    x /= c;
    c_d_count = b/x-(a-1)/x;
    cout << (b-a+1) - (c_count + d_count - c_d_count) << endl;
    return 0;
}