#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x, ans;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    if(a[0]>x){
        ans += a[0] - x;
        a[0] = x;
    }

    for(int i=1; i<n; i++){
        if(a[i] <= x-a[i-1]){
            continue;
        }
        ans += a[i] + a[i-1] - x;
        a[i] = x-a[i-1];
    }

    cout << ans << endl;
    return 0;
}