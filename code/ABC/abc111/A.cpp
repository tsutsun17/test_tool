#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    for(int i=0; i<3; i++){
        if(s[i] == '9'){
            s[i] = '1';
        }else if(s[i] == '1'){
            s[i] = '9';
        }
    }

    cout << s << endl;
    return 0;
}