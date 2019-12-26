#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)

// 点
class Point {
    public:
    double x, y;

    Point(double x=0, double y=0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x+p.x, y+p.y); }
    Point operator - (Point p) { return Point(x-p.x, y-p.y); }
    Point operator * (double a) { return Point(a*x, a*y); } // 整数倍
    Point operator / (double a) { return Point(x/a, y/a); }

    double abs() { return sqrt(norm()); }  // 大きさ
    double norm() { return x*x + y*y; }  // ノルム

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x-p.x) < EPS and fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;

// 線分
struct Segment {
    Point p1, p2;
};

// 線分交差問題
/*
    今回は線分が平行な線分交差問題(マンハッタン幾何): 交点の数を求める

    平面走査(sweep):
        x軸(またはy軸)に平行な直線を上へ(右へ)向かって平行移動させながら、交点を見つけていく
        ↑ 走査線

        1. 入力された線分の端点をy座標を基準に昇順に並び替えて、リストEPにいれる
        2. 二分探索木Tを空にする
        3. EPの端点を順番に取り出し(走査線を下から上へ移動することに対応)、以下の処理を行う
            - 取り出した端点が垂直線分の上端点 -> その線分のx座標の値をTから削除する
            - 取り出した端点が垂直線分の下端点 -> その線分のx座標の値をTに挿入する
            - 取り出した端点が水平線分の左端点(走査線が水平線分に重なる時) -> その水平線分の両端のx座標を探索の範囲として、Tに含まれる値(つまり垂直線分のx座標)を出力する

    O(nlogn + k)
*/


#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint{
    public:
        Point p;
        int seg, st; // 入力線分のID, 単点の種類
        EndPoint(){}
        EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

        bool operator < (const EndPoint &ep) const {
            // y座標が小さい順に整列
            if(p.y==ep.p.y){
                return st < ep.st;  // yが同一の時は、下端点、左端点、右端点、上端点の順に並べる
            }else return p.y < ep.p.y;
        }
};

EndPoint EP[2*100000]; // 端点のリスト

// 線分交差問題: マンハッタン幾何
int manhattanIntersection(vector<Segment> S){
    int n = S.size();

    for(int i=0, k=0; i<n; i++){
        // 端点p1, p2が左下を基準に並ぶように調整
        if(S[i].p1.y==S[i].p2.y){
            if(S[i].p1.x > S[i].p2.x) swap(S[i].p1, S[i].p2);
        }else if(S[i].p1.y > S[i].p2.y) swap(S[i].p1, S[i].p2);

        if(S[i].p1.y == S[i].p2.y){ // 水平線分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        }else{  // 垂直線分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
    }

    sort(EP, EP+(2*n)); // 端点のy座標に関して昇順に整列

    set<int> BT;    // 二分探索木
    BT.insert(1000000001);  // 番兵を設置
    int cnt = 0;

    for(int i=0; i<2*n; i++){
        if(EP[i].st==TOP){
            BT.erase(EP[i].p.x);    // 上端点を削除
        }else if(EP[i].st==BOTTOM){
            BT.insert(EP[i].p.x);   // 下端点を追加
        }else if(EP[i].st==LEFT){
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);   // O(logN)
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);   // O(logN)

            cnt += distance(b, e);   // bとeの距離(点の数)を加算 O(k)
        }
    }

    return cnt;

}

int main(){
    int n;
    cin >> n;
    vector<Segment> s;
    rep(i, n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        s.push_back(Segment{Point(x1, y1), Point(x2, y2)});
    }

    int ans = manhattanIntersection(s);

    cout << ans << endl;

    return 0;

}