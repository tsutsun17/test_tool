#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<26;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 経路復元

int n, m;
vector<P> adj[1000];
int d[1000];
int pre[1000];
bool used[1000];

void dijkstra(int s){
    fill(d, d+n, inf);
    fill(pre, pre+n, -1);
    fill(used, used+n, false);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que; // cost, to
    que.push(make_pair(0, s));
    while(!que.empty()){
        P f = que.top(); que.pop();
        int u = f.second;
        if(used[u]) continue;
        used[u] = true;
        if(d[u] < f.first) continue;
        rep(i, adj[u].size()){
            int to = adj[u][i].first;
            int cost = adj[u][i].second;
            if(d[to] > d[u] + cost){
                d[to] = d[u] + cost;
                que.push(make_pair(d[to], to));
                pre[to] = u;
            }
        }
    }

}

int main(){
    int k, u, v, c;
    cin >> n >> m;
    rep(i, m){
        cin >> u >> k;
        rep(j, k){
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }
    dijkstra(0);

    // tまでの経路

    int t = 3;
    vector<int> path;
    for(; t != -1; t = pre[t]) path.push_back(t);
    reverse(path.begin(), path.end());

    rep(i, path.size()) cout << path[i] << endl;
    return 0;
}