#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// TIPS: a1を0と仮定しても良い

int main() {
    vector< vector<int> > c(4, vector<int>(4));
    int sum = 0;
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            cin >> c[i][j];
            sum += c[i][j];
        }
    }

    if(sum%3!=0){
        cout << "No" << endl;
        return 0;
    }

    int sum1 = c[1][1]+c[2][2]+c[3][3];
    int sum2 = c[1][1]+c[2][3]+c[3][2];
    int sum3 = c[1][2]+c[2][1]+c[3][3];
    int sum4 = c[1][2]+c[2][3]+c[3][1];
    int sum5 = c[1][3]+c[2][2]+c[3][1];
    int sum6 = c[1][3]+c[2][1]+c[3][2];

    if(sum != 3*sum1 || sum != 3*sum2 || sum != 3*sum3 || sum != 3*sum4 || sum != 3*sum5 || sum != 3*sum6){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}