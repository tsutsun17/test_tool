#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

// 最短経路問題
/* 
    E: 辺数, V: 頂点数
    BFS:    O(E), コスト１
    Dijkstra:   O(ElonE)   
    Floyd Warshal:  O(V^3)
*/ 

// TIPS: Warshall–Floyd法を使う
// 辺がない場合は辺のながさを無限大にする
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int> >  c(10, vector<int>(10));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> c[i][j];
        }
    }

    // この順番 k, i, j
    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    vector<int> a;
    for(int i=0; i<h*w; i++){
        int aaa;
        cin >> aaa;
        if(aaa>=0){
            a.push_back(aaa);
        }
    }
    int ans = 0;
    for(auto aa: a){
        ans += c[aa][1];
    }

    cout << ans << endl;
    return 0;
}