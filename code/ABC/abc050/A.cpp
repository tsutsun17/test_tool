#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int a, b;
    char op;
    cin >> a >> op >> b;
    if(op=='+') cout << a+b << endl;
    else cout << a-b << endl;
    return 0;
}