#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

/*
    場合の数
        n個の箱にm個のボールをいれる入れ方(ボールと箱を区別する)の数

        ボールそれぞれに対してm通りあるため
        m^b
*/

int main() {
    int n;
    cin >> n;
    vector<int> d(n, 0);
    rep(i, n){
        int tmp;
        cin >> tmp;
        if(i==0 and tmp!=0){
            cout << 0 << endl;
            return 0;
        }
        if(i>0 and tmp==0){
            cout << 0 << endl;
            return 0;
        }
        d[tmp]++;
    }
    ll ans = 1;
    bool flag = true;
    rep(i, n){
        if(i==0) continue;
        if(d[i]==0){
            flag = false;
            continue;
        }
        if(flag){
            rep(j, d[i]){
                ans = (ans*d[i-1]) % 998244353;
            }
        }else{
            cout << 0 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}