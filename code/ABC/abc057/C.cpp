#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

vector<ll> divisor_list(ll n){
    vector<ll> ans;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            ll tmp = n/i;
            ans.push_back(tmp);
            ans.push_back(i);
        }
    }
    return ans;
}


int main() {
    ll n;
    cin >> n;
    vector<ll> res = divisor_list(n);
    int m = res.size();
    // TIPS: 桁数
    int ans = to_string(res[m-2]).length();
    cout << ans << endl;

    return 0;
}