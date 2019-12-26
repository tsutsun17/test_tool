#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int s;
    cin >> s;
    map<int, int> mm;
    int prev = s;
    mm[s] = 1;
    for(ll i=2; i<=1000000; i++){
        int tmp;
        if(prev%2){
            tmp = prev*3 + 1;
        }else{
            tmp = prev/2;
        }

        if(mm[tmp] > 0){
            cout << i << endl;
            return 0;
        }

        mm[tmp]++;
        prev = tmp;
    }
    return 0;
}