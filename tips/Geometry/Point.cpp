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

// fabsは浮動小数点の絶対値

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
// 直線
typedef Segment Line;

// 円
class Circle {
    public:
        Point c;
        double r;
        Circle(Point c=Point(), double r=0.0): c(c), r(r) {}
};

// 多角形
typedef vector<Point> Polygon;

// 内積
double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

// 外積
double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

// ベクトルの直交判定
bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0.0);
}

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
    return isOrthogonal(a1-a2, b1-b2);
}

bool isOrthogonal(Segment s1, Segment s2){
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// ベクトルの平行判定
bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2){
    return isParallel(a1-a2, b1-b2);
}

bool isParallel(Segment s1, Segment s2){
    return equals(cross(s1.p2-s1.p1, s2.p2-s2.p1), 0.0);
}

// 射影
/*
    点pから線分sに垂線を引いた時の交点x
*/
Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p-s.p1, base) / base.norm();
    return s.p1 + base*r;
}

// 反射
/*
    線分sを対象じくとして点pと線対象の位置にある点p
*/
Point relect(Segment s, Point p){
    return p+(project(s, p) - p) * 2.0;
}

// 点同士の距離
double getDistance(Point a, Point b){
    return (a-b).abs();
}

// 点と直線の距離
double getDistanceLP(Line l, Point p){
    return abs(cross(l.p2 - l.p1, p-l.p1)/(l.p2 - l.p1).abs());
}

// 点と線分の距離
double getDistanceSP(Segment s, Point p){
    if(dot(s.p2 - s.p1, p-s.p1) < 0.0) return (p-s.p1).abs();
    if(dot(s.p1 - s.p2, p-s.p2) < 0.0) return (p-s.p2).abs();
    return getDistanceLP(s, p);
}

// 反時計回りccw
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1-p0;
    Vector b = p2-p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(a.norm() < b.norm()) return ONLINE_FRONT;

    return ON_SEGMENT;
}

// 線分p1p2と線分p3p4の交差判定
/*
    0: 交差しない
    1: 交差する
*/
bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 and ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

// 線分s1と線分s2の距離
double getDistance(Segment s1, Segment s2){
    if(intersect(s1, s2)) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)), min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

// 線分の交点
Point getCrossPoint(Segment s1, Segment s2){
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1-s2.p1));
    double d2 = abs(cross(base, s1.p2-s2.p1));
    double t = d1/(d1+d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

// 円と直線の交点
pair<Point, Point> getCrossPoints(Circle c, Line l){
    // assert(intersect(c, l));  // 交点が存在するかどうかの確認
    Vector pr = project(l, c.c);
    Vector e = (l.p2-l.p1) / (l.p2-l.p1).abs();
    double base = sqrt(c.r*c.r - (pr-c.c).norm());
    return make_pair(pr+e*base, pr-e*base);
}

// pの角度
double arg(Vector p) { return atan2(p.y, p.x); }

Vector polar(double a, double r){ return Point(cos(r) * a, sin(r) * a); }


// 円c1と円c2の交点
pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
    // assert(intersect(c1, c2))  // 交差が存在するかどうかの確認
    double d = (c1.c - c2.c).abs();
    double a = acos((c1.r*c1.r + d*d - c2.r*c2.r)/(2*c1.r*d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a));
}

// 点の包含
int contain(Polygon g, Point p){  // IN: 2, ON: 1, OUT: 0
    int n = g.size();
    bool x = false;
    rep(i, n){
        Point a = g[i]-p, b = g[(i+1)%n]-p; // (i+1)%nで循環を表す
        // 外積がほぼ0かつ内積が0以下
        if(abs(cross(a,b)) < EPS and dot(a,b) < EPS) return 1;
        // 外積が正かつ半直線を跨いで異なる側に存在する時、半直線と多角形の辺g_{i}g_{i+1}が交差していると言える
        if(a.y > b.y) swap(a, b);
        if(a.y < EPS and EPS < b.y and cross(a, b) > EPS) x = !x;
    }

    return (x ? 2 : 0);
}

// 凸包
/*
    凸包: 点集合Pの全ての点を含む最小の凸多角形

    アンドリューのアルゴリズム:
        1. 与えられた点の集合をx軸について昇順に整列させる。xが同じ場合はyが小さいものを優先して整列する。
        2. 凸包の上部を次の手順で作る
            整列された点をxが小さい順に凸包Uに含めていく。ただし、点を含めるとUが凸でなくなってしまう場合は、これまでにUを含めてきた点をUが凸になるまで逆順に取り除いていく
        3. 凸包の下部を次の手順で作る
            整列された点をxが大きい順に凸包Lに含めていく。ただし、点を含めるとLが凸でなくなってしまう場合は、これまでにLに含めてきた点をLが凸になるまで逆順に取り除いていく
*/

Polygon andrewScan(Polygon s){
    Polygon u, l;
    if(s.size() < 3) return s;
    sort(s.begin(), s.end());
    // xが小さいものから２つuに追加
    u.push_back(s[0]);
    u.push_back(s[1]);
    // xが大きいものから２つlに追加
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);

    // 凸包の上部を生成
    for(int i=2; i<s.size(); i++){
        // != CLOCKWISE: 凸包の辺上の点は含めない
        // == COUNTER_CLOCKWISE: 凸包の辺上の点も含む
        for(int n=u.size(); n>=2 and ccw(u[n-2], u[n-1], s[i]) != CLOCKWISE; n--){
            u.pop_back();
        }

        u.push_back(s[i]);
    }

    // 凸包の下部を生成
    for(int i=s.size()-3; i>=0; i--){
        for(int n=l.size(); n>=2 and ccw(l[n-2], l[n-1], s[i]) != CLOCKWISE; n--){
            l.pop_back();
        }

        l.push_back(s[i]);
    }

    // 時計回りになるように凸包の点の列を生成
    reverse(l.begin(), l.end());
    for(int i=u.size()-2; i>=1; i--){
        l.push_back(u[i]);
    }
    // 反時計回り
    return l;
}

int main(){
    int n;
    cin >> n;
    Polygon g;
    rep(i, n){
        int x,y;
        cin >> x >> y;
        g.push_back(Point(x,y));
    }

    Polygon ans = andrewScan(g);
    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << "(" <<  ans[i].x << "," << ans[i].y << ")" << endl;
    }
}
