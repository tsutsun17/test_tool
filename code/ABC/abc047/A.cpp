#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a+b == c || a+c == b || b+c==a){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}