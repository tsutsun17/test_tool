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

int n;
vector<pair<ll, ll>> edges[100001];
bool visited[100001];
int ans[100001];

void solve(int cur, ll cost, int color){
    if(visited[cur]) return;
    visited[cur] = true;
    ans[cur] = cost%2 ? 1-color : color;
    rep(i, edges[cur].size()){
        pair<ll, ll> p = edges[cur][i];
        if(visited[p.first]) continue;
        solve(p.first, p.second, ans[cur]);
    }
}

int main() {
    cin >> n;
    rep(i, n-1){
        ll from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        edges[from].push_back(make_pair(to, cost));
        edges[to].push_back(make_pair(from, cost));
    }
    fill(visited, visited+n, false);
    fill(ans, ans+n, 0);
    solve(0, 0, 0);
    rep(i, n) cout << ans[i] << endl;
    return 0;
}