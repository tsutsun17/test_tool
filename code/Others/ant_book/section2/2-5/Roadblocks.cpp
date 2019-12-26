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

static const int MAX = 100;
static const int INFTY = (1<<21);

int n;
vector<P> adj[MAX]; // 重み付き有効グラフの隣接リスト表現
/*
    adj[from] = (to, cost)
*/
// d[i] := sからiまでの暫定の最短距離
int d[MAX];
int d2[MAX];

bool used[MAX];

// sからのダイクストラ
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que; // (cost, point)
    // 初期化
    fill(d, d+n, INFTY);
    fill(d2, d2+n, INFTY);
    fill(used, used+n, false);

    d[s] = 0;
    d2[s] = 0;
    que.push(make_pair(0, s));

    while(!que.empty()){
        P f = que.top();
        que.pop();
        int u = f.second;
        int c = f.first;

        if(used[u]) continue;
        // 最小値を取り出し、それが最短でなければ無視
        if(d2[u] < c) continue;

        used[u] = true;
        rep(i, adj[u].size()){
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            if(d[v] > c + cost){
                d[v] = c + cost;
                que.push(make_pair(d[v], v));
            }else if(d2[v] > c + cost and d[v] < c + cost){
                // 二番目に短い経路は1番目に短い経路もしくは2番目に短い経路を使用する
                // 最短経路は最短経路しか使わない
                d2[v] = c + cost;
                que.push(make_pair(d2[v], v));
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
    rep(i,n) cout << d2[i] << endl;
    return 0;
}