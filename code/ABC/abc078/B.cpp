#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = x-z;
    ans /= (y+z);
    cout << ans << endl;
    return 0;
}