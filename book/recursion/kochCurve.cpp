#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

struct Point { double x, y; };

// a, bの間の3点を探す
void koch(int n, Point a, Point b){
    if (n==0) return ;
    Point s, t, u;
    double th = M_PI * 60.0/180.0; // 度からラジアンに変更

    s.x = (2.0*a.x + 1.0*b.x) / 3.0;
    s.y = (2.0*a.y + 1.0*b.y) / 3.0;
    t.x = (1.0*a.x + 2.0*b.x) / 3.0;
    t.y = (1.0*a.y + 2.0*b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y-s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y-s.y) * cos(th) + s.y;

    koch(n-1, a, s);
    cout << s.x << " " << s.y << endl;
    koch(n-1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(n-1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(n-1, t, b);
}

int main(){
    int n;
    cin >> n;
    Point a, b;
    a.x = 0; a.y = 0;
    b.x = 100; b.y = 0;

    cout << a.x << " " << a.y << endl;
    koch(n, a, b);
    cout << b.x << " " << b.y << endl;
    return 0;
}