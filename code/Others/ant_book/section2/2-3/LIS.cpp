#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int n;
int a[1000], dp[1000];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    fill(dp, dp+n, (1<<21));

    rep(i, n){
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }

    int ans = lower_bound(dp, dp+n, (1<<21)) - begin(dp);
    cout << ans << endl;
    return 0;
}

/*
    arrayで二分探索する時は、初期値が埋まってる範囲で行う
    そうしないと、しっかりとした結果がでない
*/