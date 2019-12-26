#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i=0; i<h; i++){
        string ss;
        cin >> ss;
        for(int j=0; j<w; j++){
            s[i][j] = ss[j];
        }
    }

    vector<vector<int>> ans(h+2, vector<int>(w+2));
    for(int i=0; i<w+2; i++){
        ans[0][i] = 0;
        ans[h+1][i] = 0;
    }
    for(int i=0; i<h+2; i++){
        ans[i][0] = 0;
        ans[i][w+1] = 0;
    }

    for(int i=1; i<h+1; i++){
        for(int j=1; j<w+1; j++){
            if(s[i-1][j-1] == '#'){
                ans[i][j] = 10;
                ans[i][j-1]++;
                ans[i][j+1]++;
                ans[i-1][j]++;
                ans[i+1][j]++;
                ans[i+1][j+1]++;
                ans[i+1][j-1]++;
                ans[i-1][j+1]++;
                ans[i-1][j-1]++;
            }
        }
    }

    for(int i=1; i<h+1; i++){
        for(int j=1; j<w+1; j++){
            if(ans[i][j]>=10){
                cout << '#';
            }else{
                cout << ans[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}