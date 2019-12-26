#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    char prev = s[0];
    for(int i=1; i<n; i++){
        if(prev!=s[i]){
            ans++;
            prev = s[i];
        }else{
            continue;
        }
    }

    cout << ans << endl;
    return 0;
}