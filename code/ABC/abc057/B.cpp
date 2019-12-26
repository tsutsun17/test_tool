#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const ll INF = 400000001;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ab(n), cd(m);

    rep(i, n){
        cin >> ab[i].first >> ab[i].second;
    }

    rep(i, m){
        cin >> cd[i].first >> cd[i].second;
    }

    rep(i, n){
        int tmp = 0;
        ll min_dist = INF;
        rep(j, m){
            ll tmp_dist = abs(ab[i].first-cd[j].first) + abs(ab[i].second - cd[j].second);
            if(min_dist > tmp_dist){
                min_dist = tmp_dist;
                tmp = j;
            }
        }
        cout << tmp+1 << endl;
    }

    return 0;
}