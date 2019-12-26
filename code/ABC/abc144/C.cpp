#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

vector<ll> divisor_list(ll n){
    vector<ll> ans;
    // 約数のペアの小さい方はi^2までにある
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
    vector<ll> divide = divisor_list(n);
    ll x = divide[divide.size()-1];
    ll y = divide[divide.size()-2];
    cout << x+y-2 << endl;
    return 0;
}

