#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
// mapの使い方
int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i=0; i<n; i++){
        string ss;
        cin >> ss;
        sort(ss.begin(), ss.end());
        mp[ss]++;
    }
    ll ans = 0;
    for(auto& e: mp){
        ans += (ll)e.second * (e.second-1)/2;
    }

    cout << ans << endl;
    
    return 0;
}