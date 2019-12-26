#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a*c<=b){
        cout << c << endl;
    }else{
        cout << b/a << endl;
    }
    return 0;
}