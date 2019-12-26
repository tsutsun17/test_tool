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

// DAME:
/*
    lからrまでの区間はどの方向でもコストがc
        これをどのように表現するかがネック
        今回は、コスト０の逆向きの辺を作り、lからrにコストcの辺を一本作るだけで、間の辺を表現できる
    そして、ダイクストラ
*/
struct Node{
    int to;
    ll cost;
};

int n, m;
ll d[100001];
bool used[100001];

void dijkstra(vector<vector<Node>> G){
    // (cost, point)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    fill(d, d+n, INF);
    fill(used, used+n, false);
    d[0] = 0;
    que.push(make_pair(0, 0));
    while(!que.empty()){
        pair<int, int> f = que.top(); que.pop();
        int cur = f.second;
        if(used[cur]) continue;
        // 最小値ではないため、見送り
        if(d[cur] < f.first) continue;
        used[cur] = true;
        rep(i, G[cur].size()){
            int next = G[cur][i].to;
            ll cost = G[cur][i].cost;
            if(d[next] > d[cur] + cost){
                d[next] = d[cur] + cost;
                que.push(make_pair(d[next], next));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<Node>> G(n);
    // lからrにコストcの辺を追加
    rep(i, m){
        int l, r;
        ll c;
        cin >> l >> r >> c;
        l--, r--;
        G[l].emplace_back(Node{r, c});
    }
    // 逆向きの有効辺を追加
    rep(i, n-1) G[i+1].emplace_back(Node{i, 0});

    dijkstra(G);
    ll ans = (d[n-1]==INF) ? -1 : d[n-1];
    cout << ans << endl;
    return 0;
}