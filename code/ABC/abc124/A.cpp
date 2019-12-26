#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;

    for(int i=0; i<2; i++){
        if(a>b){
            ans+=a;
            a--;
        }else{
            ans+=b;
            b--;
        }
    }
    cout << ans << endl;
    return 0;
}