#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > s(m);
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        // TIPS: ここでvectorのresizeを行う
        s[i].resize(k);
        for(int j=0; j<k; j++){
            cin >> s[i][j];
            s[i][j]--;
        }
    }

    vector<int> p(m);
    for(int i=0; i<m; i++){
        cin >> p[i];
    }

    int ans=0;
    // TIPS: ビット全探索
    for(int i=0; i < (1 << n); i++){
        bool flag = true;
        for(int j=0; j<m; j++){ 
            int count = 0;
            for(auto l: s[j]){
                // TIPS: iのl番目にフラグが立っているかどうか
                if((i >> l) & 1){
                    count++; 
                }
            }
            if(count%2 != p[j]){
                flag=false;
            }
        }
        if(flag){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}