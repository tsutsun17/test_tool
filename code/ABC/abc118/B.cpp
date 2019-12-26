#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<vector<int> > a(n);
    for(int i=0; i<n; i++){
        cin >> k[i];
        a[i].resize(k[i]);
        for(int j=0; j<k[i]; j++){
            cin >> a[i][j];
        }
    }

    int ans=0;
    for(int i=1; i<m+1; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            for(int l=0; l<k[j]; l++){
                if(i==a[j][l]){
                    count++;
                    break;
                }
            }
        }
        if(count == n){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}