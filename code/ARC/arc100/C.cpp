#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] -= i+1;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    // TIPS:  bは vector aの中央値
    // 区間の中央値
    if(n%2!=0){
        int index = 0;
        index = n/2;
        for(int i=0; i<n; i++){
            ans += abs(a[i]-a[index]);
        }
    }else{
        int center = a[n/2];
        for(int i=0; i<n; i++){
            ans += abs(a[i]-center);
        }
    }
    cout << ans << endl;
    return 0;
}