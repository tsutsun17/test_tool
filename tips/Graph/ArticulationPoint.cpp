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

// 関節点, 橋
/*
    関節点: 頂点uとuから出ている全てのエッジを削除して得られる部分グラフが非連結になる頂点u
        グラフをDFSして、
            ord[i]: DFSで頂点iに訪れた順番
            low[i]: ord[i]、Backedge(i, v)が存在する時頂点におけるord[v]、DFSで生成される木内の頂点iの全ての子xに対するlow[x]の最小値
        ある頂点uが関節点である時
            1. DFSの木の根については子が2つ以上
            2. それ以外の点については頂点uのある子vについてord[u] <= low[v]を満たす

    橋: ある辺(u, v) が橋である時、 ord[u]<low[v]を満たす
*/

#define MAX 10000

vector<int> G[MAX];
int N;
bool visited[MAX];
int ord[MAX], low[MAX];
vector<int> articulation;
vector<pair<int, int>> bridge;

void DFS(int cur, int k, int par){
    // ノードcurrentを訪問した直後の処理
    ord[cur] = low[cur] = k++;
    visited[cur] = true;

    int cnt = 0;
    rep(i, G[cur].size()){
        int next = G[cur][i];
        if(!visited[next]){
            cnt++;
            // ノードcurrentからノードnextへ訪問する直前の処理
            DFS(next, k, cur);

            // ノードnextの探索が終了した直後の処理
            chmin(low[cur], low[next]);
        }else if(next != par){
            // エッジcurrent-->nextがBack-edgeの場合の処理
            chmin(low[cur], ord[next]);
        }
        // 橋判定
        if(ord[cur] < low[next]) bridge.emplace_back(minmax(cur, next));
    }

    // ノードcurrentの探索が終了した直後の処理

    // 0がroot
    if(cur == 0) return;

    if(par != 0 and ord[par] <= low[cur]) articulation.push_back(par);
    if(par == 0 and cnt > 1) articulation.push_back(par);
    return;
}

void articulate(){
    rep(i, N) visited[i] = false;
    DFS(0, 0, -1); //　ノード0から木を生成する
    sort(articulation.begin(), articulation.end());
    articulation.erase(unique(articulation.begin(), articulation.end()), articulation.end());

    rep(i, articulation.size()) cout << articulation[i] << endl;
}

void findBridge(){
    rep(i, N) visited[i] = false;
    DFS(0, 0, -1);
    sort(bridge.begin(), bridge.end());
    bridge.erase(unique(bridge.begin(), bridge.end()), bridge.end());

    rep(i, bridge.size()) cout << bridge[i].first << ":" << bridge[i].second << endl;
}



int main(){
    int m;
    cin >> N >> m;

    rep(i, m){
        int s,t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    articulate();
    findBridge();
    return 0;
}