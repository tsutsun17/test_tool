#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max({a+b, a-b, a*b}) << endl;
    return 0;
}