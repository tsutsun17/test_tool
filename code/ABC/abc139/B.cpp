#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    double a, b;
    cin >> a >> b;
    if (b == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1; i<21; i++){
        int sum = 1 + (a-1)*(i);
        if (sum >= b){
            cout << i << endl;
            return 0;
        }
    }
}