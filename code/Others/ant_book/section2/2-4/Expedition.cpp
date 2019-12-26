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

int n, l, p;
int A[10002], B[10002];

int main(){
    cin >> n >> l >> p;
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    A[n] = l;
    priority_queue<int> que;
    int pos = 0, ans = 0, tank = p;
    rep(i, n+1){
        int d = A[i] - pos;
        while(tank-d < 0){
            if(que.empty()){
                cout << -1 << endl;
                return 0;
            }
            int b = que.top();
            que.pop();
            tank += b;
            ans++;
        }

        tank -= d;
        que.push(B[i]);
        pos = A[i];
    }

    cout << ans << endl;

    return 0;
}