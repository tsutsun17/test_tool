#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    if(a>=13){
        cout << b << endl;
        return 0;
    }else if(a>=6){
        cout << b/2 << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}