#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    double ans=0;
    ans += (double)v[0]/pow(2, n-1);
    for(int i=1; i<n; i++){
        ans+=(double)v[i]/pow(2, n-i);
    }

    cout << ans << endl;
    return 0;
}