#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// グラフ
/*
    1. 隣接リスト表現
    2. 隣接行列表現

*/

// ワーシャルフロイド法: 最短経路問題 O(V^3)
vector<vector<int>> d;
void warshall_floyd(int n){
    for(int k=0; k<n; k++){         // 経由する頂点
        for(int i=0; i<n; i++){     // 始点
            for(int j=0; j<n; j++){ // 終点

                // d[i][j] : iからjまでのコスト
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

// MARK: グラフの連結判定
/*
    1. 全ての頂点を未訪問にする
    2. 任意の１つの頂点からDFS
    3. 全ての頂点が訪問済みになるならば連結であり、そうでない場合は非連結
*/


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
