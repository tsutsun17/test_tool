#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

int main() {
    int t, n, m;
    cin >> t >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> aa(n, false);

    cin >> m;

    if(n<m){
        cout << "no" << endl;
        return 0;
    }
    rep(i, m){
        int b;
        cin >> b;
        // 以上のindexを返す
        int it1 = lower_bound(a.begin(), a.end(), max(b-t, 1)) - a.begin();
        // より大きいindexを返す
        int it2 = upper_bound(a.begin(), a.end(), b) - a.begin();
        if(it1==it2){
            cout << "no" << endl;
            return 0;
        }
        for(int j=it1; j<it2; j++){
            if(!aa[j]){
                aa[j] = true;
                break;
            }
            if(j==it2-1 and aa[j]){
                cout << "no" << endl;
                return 0;
            }
        }

    }
    cout << "yes" << endl;

    return 0;
}