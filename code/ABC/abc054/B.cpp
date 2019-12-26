#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n)), b(m, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin >> b[i][j];
        }
    }

    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<n-m+1; j++){
            bool flag = true;
            for(int k=0; k<m; k++){
                for(int l=0; l<m; l++){
                    if(b[k][l]!=a[i+k][j+l]){
                        flag=false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}