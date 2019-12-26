#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    string s;
    cin >> s;
    if(s=="SUN"){
        cout << 7 << endl;
    }else if(s=="MON"){
        cout << 6 << endl;
    }else if(s=="TUE"){
        cout << 5 << endl;
    }else if(s=="WED"){
        cout << 4 << endl;
    }else if(s=="THU"){
        cout << 3 << endl;
    }else if(s=="FRI"){
        cout << 2 << endl;
    }else if(s=="SAT"){
        cout << 1 << endl;
    }
    return 0;
}