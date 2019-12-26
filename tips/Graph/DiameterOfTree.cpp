#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 木の直径
/*
    1. 適当な節点sから最も遠い節点xを求める
    2. 節点xから最も遠い節点yを求める
    3. 節点xと節点yの距離を木の直径として報告する
*/

#define MAX 100000
#define INFTY (1<<30)

vector<pair<int, int>> G[MAX];
int n, d[MAX];
bool visited[MAX];

void BFS(int s){
    rep(i, n) d[i] = INFTY;
    queue<int> que;
    que.push(s);
    d[s] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        rep(i, G[u].size()){
            int to = G[u][i].first;
            int cost = G[u][i].second;
            if(d[to] == INFTY){
                d[to] = d[u] + cost;
                que.push(to);
            }
        }
    }
}

void solve(){
    // 適当な始点sから最も遠い節点tgtを求める
    BFS(0);

    int maxv = 0;
    int tgt = 0;
    rep(i, n){
        if(d[i] == INFTY) continue;
        if(maxv < d[i]){
            maxv = d[i];
            tgt = i;
        }
    }

    // tgtからモッtも遠い節点の距離maxvを求める
    BFS(tgt);
    maxv = 0;
    rep(i, n){
        if(d[i] == INFTY) continue;
        chmax(maxv, d[i]);
    }

    cout << maxv << endl;
}

int main(){
    int s, t, w;
    cin >> n;
    rep(i, n-1){
        cin >> s >> t >> w;

        G[s].push_back(make_pair(t, w));
        G[t].push_back(make_pair(s, w));
    }

    solve();

    return 0;
}