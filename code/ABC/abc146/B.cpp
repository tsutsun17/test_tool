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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char> ans;
    rep(i, s.size()){
        char aa = s[i];
        rep(j, 26){
            if(s[i] == a[j]){
                ans.push_back(a[j+n]);
            }
        }
    }
    rep(i, s.size()){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}