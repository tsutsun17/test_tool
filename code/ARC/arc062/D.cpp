#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
// TIPS: 得点変化の条件だけを考える
int main() {
    string s;
    cin >> s;
    int n = s.size();
    int g_cnt = 0;
    int p_cnt = 0;
    int ans = 0;;
    for(int i=0; i<n; i++){
        if(g_cnt-p_cnt>0){
            // p
            if(s[i]=='g'){
                ans++;
            }
            p_cnt++;
        }else{           
            // g
            if(s[i] == 'p'){
                ans--;
            }
            g_cnt++;
        }
    }

    cout << ans << endl;

    return 0;
}