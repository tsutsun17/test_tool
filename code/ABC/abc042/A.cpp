#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ss(3);
    ss[0] = a;
    ss[1] = b;
    ss[2] = c;
    sort(ss.begin(), ss.end());

    if(ss[0] == 5 && ss[1] == 5 && ss[2] == 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}