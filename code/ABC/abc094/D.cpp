#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME: 考察系
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for(int i=0; i<n; i++){
        if(abs((double)a[n-1]/2 - a[i]) < abs((double)a[n-1]/2 - a[ans])){
            ans = i;
        }
    }

    cout << a[n-1] << ' ' << a[ans] << endl;
    return 0;
}