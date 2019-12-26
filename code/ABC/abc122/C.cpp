#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> L(n);
    vector<int> R(n);
    for(int i=0; i<q; i++){
        cin >> L[i] >> R[i];
    }

    vector<int> at(n+1);
    at[0] = 0;
    at[1] = 0;
    for(int i=2; i<n+1; i++){
        // TIPS: 部分文字列を作成 sub(a, b) a番目からb個
        string ss = s.substr(i-2, 2);
        if(ss == "AC"){
            at[i] = at[i-1] + 1;
        }else{
            at[i] = at[i-1];
        }
    }
    for(int i=0; i<q; i++){
        int ans;
        ans = at[R[i]] - at[L[i]];
        cout << ans << endl;
    }

    return 0;
}