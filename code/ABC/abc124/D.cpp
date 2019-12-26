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

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a;
    if(s[0] == '0') a.push_back(0);
    char pre = '0';
    int count = 1;
    rep(i, s.size()){
        if(pre!=s[i]){
            a.push_back(count);
            count = 0;
            pre = s[i];
        }else{
            count++;
        }
    }

    rep(i, a.size()){
        cout << a[i] << endl;
    }
    return 0;
}