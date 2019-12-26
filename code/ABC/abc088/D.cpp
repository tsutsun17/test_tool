#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 1<<30;

// DAME:
int main() {
    int h, w, wnum=0;
    cin >> h >> w;
    vector< vector<char> > s(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> s[i][j];
            if(s[i][j]=='.'){
                wnum++;
            }
        }
    }

    // TIPS: 幅優先探索BFS
    // queueの使い方
    vector< vector<int> > dist(h, vector<int>(w, INF)); // dist[i][j]: (0, 0)から(i, j)までのタイル数
    queue< pair<int, int> > que;

    // 初期値
    dist[0][0] = 1;
    que.push(make_pair(0, 0));

    // 行動パターン
    vector<int> dx{0, -1, 1, 0};
    vector<int> dy{-1, 0, 0, 1};

    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        int x = cur.first;
        int y = cur.second;
        // ここで行動を選択
        for(int dir=0; dir<4; ++dir){
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            // 境界判定
            if(nx>=0 && nx<h && ny>=0 && ny<w){
                // 白マスかつ最短距離か判定(初めて訪れたか)
                if(s[nx][ny]=='.' && dist[x][y]+1 < dist[nx][ny]){
                    // 最短距離を更新
                    dist[nx][ny] = dist[x][y]+1;
                    // queueに追加
                    que.push({nx, ny});
                }
            }
        }
    }

    if(dist[h-1][w-1] == INF){
        // ゴールできない
        cout << -1 << endl;
        return 0;
    }

    cout << wnum-dist[h-1][w-1] << endl;
    return 0;
}