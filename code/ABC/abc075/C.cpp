#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME: グラフ連結判定 DFS

/*
    連結判定
        1. 全ての頂点を未訪問にする
        2. 任意の１つの頂点からDFS
        3. 全ての頂点が訪問済みになるならば連結であり、そうでない場合は非連結

    橋判定
        各辺をグラフから取り除いてグラフが連結であるかを判定して非連結となる場合を数える
*/

// 隣接行列表現
const int limit=50;
int n,m;
int a[limit], b[limit];

bool graph[limit][limit];
bool visited[limit];

void dfs(int v){
    visited[v] = true;
    for(int v2=0; v2<n; ++v2){
        if(graph[v][v2]==false) continue;
        if(visited[v2]) continue;
        dfs(v2);
    }
}

int main() {
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
