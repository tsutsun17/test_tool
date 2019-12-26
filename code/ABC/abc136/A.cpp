#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(c-(a-b)<=0){
        cout << 0 << endl;
    }else{
        cout << c-(a-b) << endl;
    }
    return 0;
}