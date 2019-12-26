#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    double ans=0;
    for(int i=0; i<n; i++){
        ans += (double)1/a[i];
    }
    ans  = 1/ans;
    cout << setprecision(10) << ans << endl;
    return 0;
}