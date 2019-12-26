#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
// 実装力のなさ
int main() {
    int n;
    string s;
    cin >> s;
    n = s.size();
    vector<int> ans(n);
    // RとLの二種類を別々に考える考える
    for(int ri=0; ri<2; ri++) {
        // Rで考える
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if (s[i] == 'R') cnt++;
            else {
            ans[i] += cnt/2;
            ans[i-1] += (cnt+1)/2;
            cnt = 0;
            }
        }
        // LをRに変換して考える
        reverse(ans.begin(), ans.end());
        reverse(s.begin(), s.end());
        for(int i=0; i<n; i++){
            if (s[i] == 'L') s[i] = 'R';
            else s[i] = 'L';
        }
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}