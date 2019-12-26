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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    // vector<int> ll;
    // map<int, int> a;
    // rep(i, n-2){
    //     if(a[s[i] - '0'] == 0){
    //         map<int, int> b;
    //         for(int j=i+1; j<n-1; j++){
    //             if(b[s[j]-'0'] > 0) continue;
    //             map<int, int> c;
    //             for(int k=j+1; k<n; k++){
    //                 if(c[s[k]-'0'] > 0) continue;
    //                 int aa = s[j]-'0';
    //                 int bb = s[k]-'0';
    //                 int cc = s[i]-'0';
    //                 int tmp = cc*100+aa*10+bb;
    //                 ll.push_back(tmp);
    //                 c[s[k]-'0']++;
    //             }
    //             b[s[j]-'0']++;
    //         }
    //         a[s[i]-'0']++;
    //     }
    // }

    // sort(ll.begin(), ll.end());
    // ll.erase(unique(ll.begin(), ll.end()), ll.end());
    // cout << ll.size() << endl;

    int ans = 0;
    rep(i, 1000){
        string t;
        int x = i;
        rep(j, 3){
            t += '0' + x%10;
            x /= 10;
        }
        int ti = 0;
        rep(j, n){
            if(s[i] == t[ti]){
                ++ti;
                if(ti==3){
                    break;
                }
            }
            if(ti == 3){
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}