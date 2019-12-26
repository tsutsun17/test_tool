#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll L, R;
    cin >> L >> R;
    if(L*R<2019){
        cout << L*(L+1) << endl;
        return 0;
    }

    map<ll, ll> mp;
    for(ll i=L; i<=min(L+2019, R); i++){
        ll aa = i%2019;
            mp[aa]++;
    }

    // 同じ数字をかけたものが答えになることはない　必ず0が入る
    int ans = 2019;
    for(int i=0; i<2018; i++){
        if(!mp[i]){
            continue;
        }
        for(int j=i+1; j<2019; j++){
            if(!mp[j]){
                continue;
            }
            ans = min(i*j%2019, ans);
        }
    }

    cout << ans << endl;
    return 0;
}