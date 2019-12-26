#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

int main() {
    ll n;
    cin >> n;
    ll d = n%30;
    vector<int> a = {1, 2, 3, 4, 5, 6};

    rep(i, d){
        ll j = i%5;
        swap(a[j], a[j+1]);
    }

    rep(i, 6) cout << a[i];
    cout << endl;
    return 0;
}