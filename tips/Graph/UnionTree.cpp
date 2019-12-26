#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

class UnionFind {
    // 経路圧縮によるrank更新はなし
    public:
        vector<int> rank, par, size; // rank[x]: xの高さ, par[x]: xの親のノード, size[x]: x

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

        // 単純に繋げない場合
        if(rank[x]==rank[y]) rank[x]++;

        // 単純に一列につなげる場合
        // rank[x] += rank[y];


        par[y] = x;
        return true;
    }

    int getRank(int x){
        return rank[findRoot(x)] + 1;
    }
};

int main(){
    int n, a, b, q;
    int t;

    cin >> n >> q;
    UnionFind ds = UnionFind(n);
    rep(i, q){
        cin >> t >> a >> b;
        if(t==0) ds.unite(a, b);
        else if (t==1){
            if (ds.same(a, b)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}