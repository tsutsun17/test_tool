#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// DAME:
int gcd(ll x, ll y){
    if(x<y){
        swap(x, y);
    }
    if(y==0){
        return x;
    }
    return gcd(y, x%y);
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;

    return 0;
}