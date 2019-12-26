#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, a;
    cin >> n >> a;
    int nn = n%1000;
    int m3 = (nn/100)%5;

    if(n>a){
        if(m3*100+(nn%100) > a){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}