#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i, h)rep(j, w){
        char tmp;
        cin >> tmp;
        s[i][j] = tmp;
    }
    int num = 1;
    vector<vector<int>> ans(h, vector<int>(w));
    rep(j, w){
        stack<P> a;
        bool flag = false;
        rep(i, h){
            a.push(make_pair(i, j));
            if(s[i][j]=='#'){
                flag = true;
                while(!a.empty()){
                    int x = a.top().first;
                    int y = a.top().second;
                    a.pop();
                    ans[x][y] = num;
                }
                num++;
                continue;
            }
            if(i == h-1){
                if(flag){
                    while(!a.empty()){
                        int x = a.top().first;
                        int y = a.top().second;
                        a.pop();
                        ans[x][y] = num-1;
                    }
                }else{
                    while(!a.empty()){
                        int x = a.top().first;
                        int y = a.top().second;
                        a.pop();
                        ans[x][y] = -1;
                    }
                }
            }
        }
    }

    rep(i, h){
        stack<int> a;
        int nn;
        rep(j, w){
            a.push(j);
            if(ans[i][j] == -1){
                continue;
            }else{
                nn = ans[i][j];
                while(!a.empty()){
                    int kk = a.top();
                    a.pop();
                    ans[i][kk] = nn;
                }
            }
        }
    }

    rep(i, h){
        stack<int> a;
        int nn;
        for(int j=w-1; j>=0; j--){
            a.push(j);
            if(ans[i][j] == -1){
                continue;
            }else{
                nn = ans[i][j];
                while(!a.empty()){
                    int kk = a.top();
                    a.pop();
                    ans[i][kk] = nn;
                }
            }
        }
    }

    rep(i, h)rep(j, w){
        cout << ans[i][j] << ' ';
        if(j==w-1){
            cout << endl;
        }
    }

    return 0;
}