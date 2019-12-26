#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int n;
vector<P> adj[100001];
ll kd[100001];
bool used[100001];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que; // (cost, point)
    // 初期化
    fill(kd, kd+n, 1LL << 50);
    fill(used, used+n, false);

    kd[s] = 0;
    que.push(make_pair(0, s));

    while(!que.empty()){
        P f = que.top();
        que.pop();
        ll c = f.first;
        ll u = f.second;

        if(used[u]) continue;
        // 最小値を取り出し、それが最短でなければ無視
        if(kd[u] < c) continue;
        used[u] = true;
        rep(i, adj[u].size()){
            ll v = adj[u][i].first;
            ll cost = adj[u][i].second;
            // d[u] = f.first
            if(kd[v] > c + cost){
                kd[v] = c + cost;
                que.push(make_pair(kd[v], v));
            }
        }
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i, n-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));;
    }
    int q, k;
    cin >> q >> k;
    k--;
    dijkstra(k);

    rep(i, q){
        int x,y;
        cin >> x >> y;
        x--; y--;
        cout << kd[x] + kd[y] << endl;
    }
    return 0;
}