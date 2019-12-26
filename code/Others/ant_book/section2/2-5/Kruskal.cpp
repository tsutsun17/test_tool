#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

#define MAX 10000
#define INFTY 1<<29

class UnionFind {
    // 経路圧縮によるrank更新はなし
    public:
        vector<int> rank, par; // rank[x]: xの高さ, par[x]: xの親のノード

    // 初期化
    UnionFind() {}
    UnionFind(int size){
        rank.resize(size, 0);
        par.resize(size, 0);
        rep(i, size) makeSet(i);
    }

    void makeSet(int x){
        par[x] = x;
        rank[x] = 0;
    }

    // 根を再帰的に求める(経路圧縮)
    int findRoot(int x){
        if(x != par[x]){
            par[x] = findRoot(par[x]);
        }
        return par[x];
    }

    // 根が同じかどうか
    bool same(int x, int y){
        return findRoot(x) == findRoot(y);
    }

    //  xとyの木を併合
    bool unite(int x, int y){
        x = findRoot(x);
        y = findRoot(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) swap(x, y);
        if(rank[x]==rank[y]) rank[x]++;
        par[y] = x;
        return true;
    }
};

class Edge{
    public:
    int from, to, cost;
    Edge(int from=0, int to=0, int cost=0): from (from), to(to), cost(cost) {}
    bool operator < (const Edge &e) const {
        return cost < e.cost;
    }
};

// クラスかるのアルゴリズム
int kruskal(int N, vector<Edge> edges){
    // 最小全域木の総コスト
    int totalCost = 0;
    // costの昇順に整列
    sort(edges.begin(), edges.end());
    UnionFind mst = UnionFind(N);

    // costが小さい順にUnionFind木に追加していく
    rep(i, edges.size()){
        Edge e = edges[i];

        if(!mst.same(e.from, e.to)){
            totalCost += e.cost;
            mst.unite(e.from, e.to);
        }
    }

    return totalCost;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    rep(i, M){
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back(Edge(from, to, cost));
    }

    cout << kruskal(N, edges) << endl;

    return 0;
}
