#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int a=0, b=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            a++;
        }else{
            b++;
        }
    }
    if(a==0 || b==0){
        cout << 0 << endl;
        return 0;
    }else{
        cout << 2 * min(a, b) << endl;
        return 0;
    }
}