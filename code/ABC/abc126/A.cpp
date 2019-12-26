#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // TIPS: 大文字を小文字へ
    s[k-1] = tolower(s[k-1]);
    cout << s << endl;
    return 0;
}