#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// TIPS: priority_queue
int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<ll> a;
    for(int i=0; i<n; i++){
        ll ii;
        cin >> ii;
        a.push(ii);
    }

    for(int i=0; i<m; i++){
        ll top = a.top();
        top /= 2;
        a.pop();
        a.push(top);
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ll tmp = a.top();
        a.pop();
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}