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

int main(){
    int n, k;
    cin >> n >> k;
    int T[k+1], X[k+1], Y[k+1];
    // x, x+N, x+2*N をx-A, x-B, x-Cの要素とする
    UnionFind unionfind = UnionFind(n*3);

    int ans = 0;
    rep(i, k){
        int t = T[i];
        int x = X[i]-1, y = Y[i]-1;
        if(x<0 or y<0 or n<=x or n<=y){
            ans++;
            continue;
        }

        // 成り立っていると仮定できるものを全てunionfind木にいれる

        if(t == 1){
            // xとyが違う木の時
            if(unionfind.same(x, y+n) or unionfind.same(x, y+2*n)){
                ans++;
            }else{
                unionfind.unite(x, y);    // x-A, y-A
                unionfind.unite(x+n, y+n);    // x-B, y-B
                unionfind.unite(x+2*n, y+2+n);    // x-C, y-C
            }
        }else{
            // x_Aとy_Aが同じ木だとだめ
            // x_Aとy_Cが同じ木だとだめ
            if(unionfind.same(x, y) or unionfind.same(x, y+2*n)){
                ans++;
            }else{
                unionfind.unite(x, y+n);    // x_A, y_B
                unionfind.unite(x+n, y+2*n);    // x_B, y_C
                unionfind.unite(x+2*n, y);  // x_C, y_A
            }
        }
    }

    cout << ans << endl;

    return 0;
}