#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) {
        cout << "Bad" << endl;
        return 0;
    }
    cout << "Good" << endl;
}
