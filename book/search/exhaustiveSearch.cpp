#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    vector<int> ans_l;
    for(int bit = 1; bit < (1<<n); bit++){
        int ans = 0;
        rep(i, n){
            if(bit & (1<<i)) {
                ans += A[i];
            }
        }
        ans_l.push_back(ans);
    }

    sort(ans_l.begin(), ans_l.end());
    int q;
    cin >> q;
    rep(i, q){
        int m;
        cin >> m;
        auto itl = lower_bound(ans_l.begin(), ans_l.end(), m);
        auto itu = upper_bound(ans_l.begin(), ans_l.end(), m);

        if(itl - itu) cout << "yes" << endl;
        else cout << "no" << endl;
    }





}