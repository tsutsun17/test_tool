#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i=a; i<=b; i++){
        bool flag = true;
        string k = to_string(i);
        for(int j=0; j<k.size()/2; j++){
            if(k[j]!=k[k.size()-j-1]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}