#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    vector<ll> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    ll ans = 0;
    for(int i=1; i<n; i++){
        ll tmp = x[i] - x[i-1];
        if(tmp * a > b){
            ans += b;
        }else{
            ans += tmp*a;
        }
    }

    cout << ans << endl;
    return 0;
}