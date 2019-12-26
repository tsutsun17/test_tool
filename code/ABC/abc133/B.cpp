#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, d;
    cin >> n >> d;
    vector< vector<int> > x(n, vector<int>(d));
    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            cin >> x[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            double sum = 0;
            for(int k=0; k<d; k++){
                sum += pow(x[i][k] - x[j][k], 2);
            }
            sum = pow(sum, 0.5);

            // TIPS: 整数判定
            if(ceil(sum)==int(sum)){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}