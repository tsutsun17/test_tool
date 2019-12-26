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

// DAG: 閉路のない有向グラフ

// トポロジカルソート
/*
    トポロジカルソート
        DAGの各辺(u,v)について、uがvよりも先に位置するように並べること

        1. 入次数が0のものからBFSをする
        2. BFSのqueueに加わった節点からの出リンクを消す
        3. 入次数が0になったものをqueueにいれる

    O(|V| + |E|)
*/

static const int MAX = 100000;
static const int INFTY = (1<<29);

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX]; // indeg[v] := vの入リンク数

void BFS(int s){
    queue<int> q;
    q.push(s);
    V[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        out.push_back(u);

        rep(i, G[u].size()){
            int v = G[u][i];
            indeg[v]--;
            // 入リンクが0だったらqueueに追加
            if(indeg[v] == 0 and !V[v]){
                V[v] = true;
                q.push(v);
            }
        }
    }
}

// トポロジカルソート
void tsort(){
    rep(i, N) indeg[i] = 0;

    rep(u, N)rep(i, G[u].size()){
        int v = G[u][i];
        indeg[v]++;
    }
    rep(u, N){
        // 入リンクが0のものからBFSをする
        if(indeg[u] == 0 and !V[u]) BFS(u);
    }

    for(list<int>::iterator it = out.begin(); it != out.end(); it++){
        cout << *it << endl;
    }
}

int main(){
    int s, t, M;
    cin >> N >> M;

    rep(i, N) V[i] = false;

    rep(i, N){
        cin >> s >> t;
        G[s].push_back(t);
    }

    tsort();

    return 0;
}


