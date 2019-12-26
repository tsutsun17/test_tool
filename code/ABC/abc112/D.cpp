#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i=pow(m, 0.5)+1; i>=1; i--){
        if(m%i==0){
            int tmp = m/i;
            if(tmp*n<=m){
                ans = max(ans, tmp);
            }
            if(i*n<=m){
                ans = max(ans, i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}