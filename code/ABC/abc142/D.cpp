#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

/*
    最大公約数の素因数の個数+1

    a, bの公約数　＝ GCD(a, b)の約数
*/

// ユークリッドの互除法: x>y
ll gcd(ll x, ll y){
    if(y==0) return x;
    return gcd(y, x%y);
}

// 素因数分解: vector(素因数, 数)
vector<pair<ll, int> > factorize(ll n){
    vector< pair<ll, int> > res;
    // nが変化していく
    for(ll i=2; i*i <= n; ++i){
        if(n%i){
            continue;
        }
        res.emplace_back(i, 0);
        while(n%i==0){
            n/=i;
            res.back().second++;
        }
    }
    if(n != 1){
        res.emplace_back(n, 1);
    }
    return res;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);

    auto f = factorize(g);
    int ans = f.size()+1;
    cout << ans << endl;
    return 0;
}


