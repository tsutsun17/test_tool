#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char> > a(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char aa;
            cin >> aa;
            a[i][j] = aa;
        }
    }

    vector<int> ha(h);
    vector<int> wa(w);

    for(int i=0; i<h; i++){
        bool flag = true;
        for(int j=0; j<w; j++){
            if(a[i][j]=='#'){
                flag = false;
                break;
            }
        }

        if(flag){
            ha[i] = 1;
        }
    }

    for(int i=0; i<w; i++){
        bool flag = true;
        for(int j=0; j<h; j++){
            if(a[j][i]=='#'){
                flag = false;
                break;
            }
        }

        if(flag){
            wa[i] = 1;
        }
    }

    for(int i=0; i<h; i++){
        if(ha[i]){
            continue;
        }
        for(int j=0; j<w; j++){
            if(wa[j]){
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }


    return 0;
}