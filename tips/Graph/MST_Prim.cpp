#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 最小全域木(MST): 辺の重みの総和が最小のもの
/*
    Prim's Algorithm
        グラフ G=(V, E) の頂点全体の集合をV, MSTに属する頂点の集合をT
        1. Gから任意の頂点rを選び、それをMSTのルートとして、Tに追加する
        2. 次の処理をT＝Vになるまで繰り返す
            Tに属する頂点とVーTに属する頂点を繋ぐ辺の中で、重みが最小のものである辺(from, to)を選び、それをMSTの辺とし、toをTに追加する

    変数:
    M[n]: M[from] := pair(to, cost)
    d[n]: 暫定の任意の点からその頂点にいくための最小重み
    used[n]: Tに追加したかどうか

    priority_queueと隣接リストにより、O((N+E)logN)
*/
static const int MAX = 100;
static const int INFTY = (1<<21);

int n;
vector<pair<int, int>> M[MAX]; // M[from] := (to, cost)
int d[MAX]; // 任意の点からその点にいくための暫定の最小重み
bool used[MAX]; // 訪問したかどうか

void prim(int r){ // rは任意の点
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que; // (cost, point)
    fill(d, d+n, INFTY);
    fill(used, used+n, 0);
    que.push(make_pair(0, r));

    while(!que.empty()){
        int c = que.top().first;
        int u = que.top().second;
        que.pop();

        // 訪問済みだったらcontinue
        if(used[u]) continue;
        used[u] = 1;
        d[u] = c;
        rep(i, M[u].size()){
            int v = M[u][i].first;
            int cost = M[u][i].second;
            que.push(make_pair(cost, v));
        }
    }
}

int main(){
    cin >> n;
    rep(i, n)rep(j, n){
        int e; cin >> e;
        if(e == -1){
            M[i].push_back(make_pair(j, INFTY));
        }else{
            M[i].push_back(make_pair(j, e));
        }

    }
    prim(0);
    rep(i, n){
        cout << d[i] << endl;
    }
    return 0;
}