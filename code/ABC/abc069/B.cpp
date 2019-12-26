#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    cout << s[0] << n-2 << s[n-1] << endl;
    return 0;
}