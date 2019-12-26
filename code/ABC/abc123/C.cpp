#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> keiro(5);
    for(int i=0; i<5; i++){
        cin >> keiro[i];
    }
    ll min_k = *min_element(keiro.begin(), keiro.end());
    ll ans = 0;
    if(n%min_k == 0){
        ans += n/min_k-1;
    }else{
        ans += n/min_k;
    }
    ans += 5;
    cout << ans << endl;
    return 0;
}