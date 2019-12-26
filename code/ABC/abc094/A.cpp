#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    if(x-a<=b && x-a>=0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}