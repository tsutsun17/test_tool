#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    int sum = 0;
    rep(i, n){
        cin >> l[i];
        sum += l[i];
    }

    sort(l.begin(), l.end());
    if(l[n-1] < sum-l[n-1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}