#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int a, b;
    cin >> a>> b;
    if(a>=10 || b>=10){
        cout << -1 << endl;
    }else{
        cout << a * b << endl;
    }
    return 0;
}