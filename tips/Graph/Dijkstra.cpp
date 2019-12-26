#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

static const int MAX = 100;
static const int INFTY = (1<<21);

int n;
vector<P> adj[MAX]; // 重み付き有効グラフの隣接リスト表現
/*
    adj[from] = (to, cost)
*/
// d[i] := sからiまでの暫定の最短距離
int d[MAX];

bool used[MAX];

// sからのダイクストラ
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que; // (cost, point)
    // 初期化
    fill(d, d+n, INFTY);
    fill(used, used+n, false);

    d[s] = 0;
    que.push(make_pair(0, s));

    while(!que.empty()){
        P f = que.top();
        que.pop();
        int c = f.first;
        int u = f.second;

        if(used[u]) continue;
        // 最小値を取り出し、それが最短でなければ無視
        if(d[u] < c) continue;
        used[u] = true;
        rep(i, adj[u].size()){
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            // d[u] = f.first
            if(d[v] > c + cost){
                d[v] = c + cost;
                que.push(make_pair(d[v], v));
            }
        }
    }
}

int main(){
    int k, u, v, c;
    cin >> n;
    rep(i, n){
        cin >> u >> k;
        rep(j, k){
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }
    // 0からのダイクストラ
    dijkstra(0);
    rep(i,n) cout << d[i] << endl;
    return 0;
}