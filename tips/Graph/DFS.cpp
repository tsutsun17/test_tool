#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// MARK: グラフの連結判定
/*
    1. 全ての頂点を未訪問にする
    2. 任意の１つの頂点からDFS
    3. 全ての頂点が訪問済みになるならば連結であり、そうでない場合は非連結
*/




// MARK: 辺のコストが１, 無向グラフ
vector<bool> seen;

// Graph: 隣接リスト表現
void dfs(const Graph &G, int v){
    seen[v] = true; // vを訪問済みにする

    // vからいける各頂点 next_vについて
    for(auto next_v : G[v]){
        if(seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int dfs_main(){
    int n, m;
    cin >> n >> m;

    // グラフ入力受け取り(ここでは無向グラフを想定)
    // 有向グラフの場合は、G[a].push_back(b)だけでいい
    Graph G(n);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点0をスタートとした探索
    seen.assign(n, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
}






// MARK: 辺に重みがある場合
struct Edge {
    int to;      // 辺の行き先
    int weight;  // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};

using Graph_weight = vector<vector<Edge>>;

int weight_dfs(){
    // 頂点数と変数
    int n, m;
    cin >> n >> m;

    Graph_weight G(n);
    for(int i=0; i<m; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        G[from].push_back(Edge(to, weight));
    }
}






// MARK: 橋判定
/*
    各辺をグラフから取り除いてグラフが連結であるかを判定して非連結となる場合を数える
*/
const int limit=50;
int n,m;
int a[limit], b[limit];

bool graph[limit][limit];
bool visited[limit];

// 隣接行列を利用した時のDFS
void dfs(int v){
    visited[v] = true;
    for(int v2=0; v2<n; ++v2){
        if(graph[v][v2]==false) continue;
        if(visited[v2]) continue;
        dfs(v2);
    }
}

int bridge_main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    int ans = 0;

    for(int i=0; i<m; ++i){
        // 辺を取り除く
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

        // visitedの初期化
        for(int j=0; j<n; ++j){
            visited[j] = false;
        }

        dfs(0);

        // visitedに一つでもfalseが存在するとき非連結
        bool bridge = false;
        for(int j=0; j<n; ++j){
            if(visited[j]==false) bridge = true;
        }

        if(bridge) ans += 1;

        // 元に戻す
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    cout << ans << endl;
    return 0;
}


