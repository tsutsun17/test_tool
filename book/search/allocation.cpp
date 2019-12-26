#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int n, k;
vector<ll> T;

// 最大積載量 P のk台のトラックで何個の荷物を詰めるか?
int check(ll P){
    int i=0;
    rep(j, k){
        ll s = 0;
        while(s+T[i] <= P){
            s += T[i];
            i++;
            if(i==n) return n;
        }
    }
    return i;
}

// Pを二分探索で求める
int solve(){
    ll left = 0;
    ll right = 100000 * 100000; // 荷物の個数 * １個当たりの最大重量
    ll mid;
    while(right-left > 1){
        mid = (left+right)/2;
        int v = check(mid); // mid==P　を決めて何個詰めるかをチェック
        if(v>=n) right = mid;
        else left = mid;
    }

    return right;
}

int main(){
    cin >> n >> k;
    T.resize(n, 0);
    rep(i, n) cin >>  T[i];

    ll ans = solve();
    cout << ans << endl;
}