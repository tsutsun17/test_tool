#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

// kd木
/*
    kd木
        k次元のユークリッド空間にある点を分類するデータ構造(二分木)
        二分木の深さによって、どの次元でソートするのかを決め、その中央値で分類する
*/

class Node{
    public:
        int location;
        int pa, l, r;
        Node(){}
};

// 今回は二次元: 実際の座標
class Point{
    public:
        int id, x, y;
        Point(){}
        Point(int id, int x, int y): id(id), x(x), y(y) {}

        bool operator < (const Point &p) const {
            return id < p.id;
        }

        void print(){
            printf("%d\n", id); // cout よりも高速なprintfを使用
        }
};

static const int MAX = 1000000;
static const int NIL = -1;

int N;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y; }

int makeKDTree(int l, int r, int depth){
    // l, r はNode番号
    if(!(l<r)) return NIL;
    int mid =  (l+r)/2;
    int t = np++;
    // 今回は二次元
    if(depth%2==0){
        sort(P+l, P+r, lessX);
    }else{
        sort(P+l, P+r, lessY);
    }

    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth+1);
    T[t].r = makeKDTree(mid+1, r, depth+1);

    return t;
}

// 二次元の領域探索
void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans){
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if(sx<=x and x<=tx and sy<=sy and y<=ty){
        ans.push_back(P[T[v].location]);
    }

    // 深さによってソート順番が違うため、深さによって基準軸を変える
    if(depth%2 == 0){
        if(T[v].l != NIL){
            if(sx <= x) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }

        if(T[v].r != NIL){
            if(x<=tx) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
        }
    }else{
        if(T[v].l != NIL){
            if(sy<=y) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }

        if(T[v].r != NIL){
            if(y<=ty) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
        }
    }
}

int main(){
    int x, y;
    scanf("%d", &N);
    rep(i, N){
        scanf("%d %d", &x, &y);
        P[i] = Point(i, x, y);
        T[i].l = T[i].r = T[i].pa = NIL;
    }

    np = 0;
    int root = makeKDTree(0, N, 0);

    int q;
    scanf("%d", &q);
    int sx, tx, sy, ty;
    vector<Point> ans;
    rep(i, q){
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear(); // vectorのサイズだけを0にする(メモリサイズは変わらない)
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        rep(j, ans.size()){
            ans[j].print();
        }
    }

    return 0;

}

