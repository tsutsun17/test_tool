#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> st(5);
    for(int i=0; i<5; i++){
        cin >> st[i];
    }
    int minin=0;
    for(int i=1; i<5; i++){
        // TIPS: １のくらいは%10で出てくる
        int pre = st[minin]%10;
        int next = st[i]%10;
        if(next < pre && next != 0){
            minin = i;
        }
    }
    int ans=0;
    for(int i=0; i<5; i++){
        if(i==minin){
            ans+=st[i];
            continue;
        }
        if(st[i]%10 == 0){
            ans += st[i];
        }else{
            int aa = st[i]/10 + 1;
            ans += aa*10;
        }
    }
    cout << ans << endl;
    return 0;
}