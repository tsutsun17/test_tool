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

int n, L[20001];

int main(){
    cin >> n;
    ll ans = 0;
    // Lを小さいものから合成することを考える
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i, n){
        int tmp;
        cin >> tmp;
        que.push(tmp);
    }
    while(que.size() > 1){
        int f = que.top(); que.pop();
        int s = que.top(); que.pop();
        que.push(f+s);
        ans += f+s;
    }

    cout << ans << endl;
    return 0;
}