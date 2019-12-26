#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, t;
    cin >> a >> b >> t;
    // TIPS: int同士の/では商がintで出てくる
    int count = t/a;
    count *= b;
    cout << count << endl;
    return 0;
}