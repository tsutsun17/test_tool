#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool flag = true;

    for(int i=0; i<n; i++){
        if(i%2){
            if(s[i]=='R'){
                flag = false;
                break;
            }
        }else{
            if(s[i]=='L'){
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