#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n){
        ll tmp;
        cin >> tmp;
        if(i==0){
            a[i] = tmp;
        }else{
            a[i] = a[i-1] + tmp;
        }
    }
    ll mid = a[n-1]/2;
    auto itr = lower_bound(a.begin(), a.end(), mid);
    if(*itr == mid and a[n-1] % 2 == 0){
        cout << 0 << endl;
    }else{
        vector<ll> b(3);
        int index = itr - a.begin();
        if(index != 0){
            b[0] = a[index-1];
            b[1] = a[index] - a[index-1];
            b[2] = a[n-1] - a[index];
        }else{
            b[0] = a[index];
            b[1] = 0;
            b[2] = a[n-1] - a[index];
        }
        ll ans = min(abs(b[0]+b[1]-b[2]), abs(b[1]+b[2]-b[0]));
        cout << ans << endl;
    }
    return 0;
}