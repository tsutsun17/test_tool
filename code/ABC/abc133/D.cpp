#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<ll> ans(n);
    for(int i=0; i<n; i++){
        if(i%2){
            ans[0] -= a[i];
        }else{
            ans[0] += a[i];
        }
    }
    cout << ans[0] << ' ';
    for(int i=1; i<n; i++){
        ans[i] = -1 * ans[i-1] + (2*a[i-1]);
        cout << ans[i] << ' ';
    }
    return 0;
}