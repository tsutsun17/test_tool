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
    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    int ai=0, bi=0, ci=0;
    char deban = 'a';

    rep(i, 305){
        if(deban == 'a'){
            deban = sa[ai];
            if(ai==sa.size()){
                cout << "A" << endl;
                return 0;
            }
            ai++;
        }else if(deban == 'b'){
            deban = sb[bi];
            if(bi==sb.size()){
                cout << "B" << endl;
                return 0;
            }
            bi++;
        }else{
            deban = sc[ci];
            if(ci==sc.size()){
                cout << "C" << endl;
                return 0;
            }
            ci++;
        }
    }
    return 0;
}