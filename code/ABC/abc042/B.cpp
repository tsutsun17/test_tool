#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    string ans;
    for(int i=0; i<n; i++){
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}