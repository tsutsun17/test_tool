#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

// TIPS: 一筆書きを考える
int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n+1);
    a[0] = 0;
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }

    vector<vector<int> > ans(h+1, vector<int>(w+1));
    int tmp = 1;
    for(int i=1; i<=h; i++){
        if(i%2){
            for(int j=1; j<=w; j++){
                if(!a[tmp]){
                    tmp++;
                }
                ans[i][j] = tmp;
                a[tmp]--;
            }
        }else{
            for(int j=w; j>=1; j--){
                if(!a[tmp]){
                    tmp++;
                }
                ans[i][j] = tmp;
                a[tmp]--;
            }
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}