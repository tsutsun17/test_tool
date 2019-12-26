#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// BFS

/*
    d[u] := sからuまでの距離

    1. 始点sをqueueにいれる
    2. queueがからでない限り以下の処理を繰り返す
        - queueから頂点uを取り出し訪問する
        - uに隣接し未訪問の頂点vについてd[v]をd[u]+1と更新し、vをqueueにいれる
*/

static const int MAX = 100000;
static const int INFTY = (1<<29);

vector<int> M[MAX];
bool visited[MAX];
int d[MAX];
int n;

void BFS(int s){
    queue<int> que;
    que.push(s);
    visited[s] = true;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        rep(i, M[u].size()){
            int v = M[u][i];
            if(!visited[v]){
                visited[v] = true;
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    }
    rep(i, n){
        cout << i+1 << " " << ((d[i]==INFTY) ? (-1) : d[i]) << endl;
    }
}
int main(){
    int u, k, v;
    cin >> n;

    fill(d, d+n, 0);

    rep(i, n){
        cin >> u >> k;
        u--;
        rep(j, k){
            cin >> v;
            v--;
            M[u].push_back(v);
        }
    }

    BFS(0);

    return 0;
}