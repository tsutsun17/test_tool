#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b;
    cin >> a>> b;
    int ans = max(a-2*b, 0);
    cout << ans << endl;
    return 0;
}