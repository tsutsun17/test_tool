#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool flag = true;
    for(int i=0; i<s.size(); i++){
        if(i<=a-1){
            if(s[i] - '0' < 0 || s[i] - '0' > 9){
                flag = false;
                break;
            }
        }else if(i==a){
            if(s[i] != '-'){
                flag = false;
                break;
            }
        }else{
            if(s[i] - '0' < 0 || s[i] - '0' > 9){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}