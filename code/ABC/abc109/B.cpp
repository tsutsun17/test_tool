#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<string> w(n), w_u(n);

    rep(i, n){
        cin >> w[i];
        w_u[i] = w[i];
    }

    sort(w_u.begin(), w_u.end());
    w_u.erase(unique(w_u.begin(), w_u.end()), w_u.end());

    if(w.size() != w_u.size()){
        cout << "No" << endl;
        return 0;
    }

    bool flag= true;
    rep(i, n){
        if(i==0) continue;
        int size = w[i-1].size();
        if(w[i-1][size-1] != w[i][0]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}