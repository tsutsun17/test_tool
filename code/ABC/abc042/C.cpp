#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
// TIPS: 愚直にnに1を追加していく
// （理由）: 1 <= n <= 9999であり、それぞれの桁の判断もかける5*k
// 答えの範囲は n <= ans <= 88888　探索回数はこれかける5*k未満
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    for(int i=0; i<k; i++){
        cin >> d[i];
    }
    int ans = n;
    while(1){
        bool flag = true;
        for(int i=0; i<to_string(ans).size(); i++){
            for(int j=0; j<k; j++){
                if(to_string(ans)[i] - '0'== d[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == false){
                break;
            }
        }
        if(flag){
            break;
        }else{
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}