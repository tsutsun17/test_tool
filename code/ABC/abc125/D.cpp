#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int count = 0;
    for(int i=0; i<n; i++){
        ll aa;
        cin >> aa;
        a[i] = abs(aa);
        if(aa<0){
            count++;
        }
    }
    sort(a.begin(), a.end());
    ll ans=0;
    for(int i=0; i<n; i++){
        ans+=a[i];
    }
    if(count%2 == 1){
        ans -= 2*a[0];
    }
    cout << ans << endl;
    return 0;
}