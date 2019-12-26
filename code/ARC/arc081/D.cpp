#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

// 制約充足問題っぽい
int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<ll> ans(n);
    int index = 1;
    if(s1[0]==s2[0]){
        ans[0] = 3;
    }else{
        ans[1] = 3*2;
        index++;
    }
    bool flag = true;
    for(int i=index; i<n; i++){
        if(s1[i]==s2[i]){
            if(s1[i-1] == s2[i-1]){
                ans[i] = ans[i-1] * 2;
            }else{
                ans[i] = ans[i-1];
            }
        }else{
            if(flag){
                flag = false;
            }else{
                if(s1[i-2] == s2[i-2]){
                    ans[i] = ans[i-2] * 2;
                }else{
                    ans[i] = ans[i-2] * 3;
                }
                flag = true;
            }
        }
        ans[i] = ans[i] % MOD;
    }

    cout << ans[n-1] << endl;
    return 0;
}