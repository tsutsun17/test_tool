#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
int main() {
    ll n;
    cin >> n;
    vector<int> a(n+1);
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    vector<int> ans(n+1);

    for(ll i=n; i>=1; i--){
        ll tmp = i;
        int sum = 0;
        while(tmp+i<=n){
            tmp += i;
            sum += ans[tmp];
        }
        if(sum%2 != a[i]){
            ans[i] = 1;
        }
    }
    int size = 0;
    for(ll i=1; i<=n; i++){
        if(ans[i]){
            size++;
        }
    }
    cout << size << endl;
    for(ll i=1; i<=n; i++){
        if(ans[i]){
            cout << i << ' ';
        }
    }

    return 0;
}