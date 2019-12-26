#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// DAME:
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2));
    rep(i, h+2){
        s[i][0] = '#';
        s[i][w+1] = '#';
    }
    rep(j, w+2){
        s[0][j] = '#';
        s[h+1][j] = '#';
    }
    rep(i, h)rep(j, w){
        cin >> s[i+1][j+1];
    }
    vector<vector<int>> L(h+2, vector<int>(w+2, 0));
    vector<vector<int>> R(h+2, vector<int>(w+2, 0));
    vector<vector<int>> U(h+2, vector<int>(w+2, 0));
    vector<vector<int>> D(h+2, vector<int>(w+2, 0));
    rep(i, h+1)rep(j, w+1){
        if(i==0 or j==0) continue;
        if(s[i][j] == '#'){
            L[i][j] = 0;
            R[i][j] = 0;
            U[i][j] = 0;
            D[i][j] = 0;
            continue;
        }
        L[i][j] = L[i][j-1]+1;
        U[i][j] = U[i-1][j]+1;
    }

    for(int i=h+1; i>0; i--)for(int j=w+1; j>0; j--){
        if(s[i][j] == '.'){
            R[i][j] = R[i][j+1]+1;
            D[i][j] = D[i+1][j]+1;
        }
    }
    int ans = 0;
    rep(i, h+1)rep(j, w+1){
        if(i==0 or j==0) continue;
        chmax(ans, L[i][j]+R[i][j]+U[i][j]+D[i][j]-3);
    }
    cout << ans << endl;
    return 0;
}