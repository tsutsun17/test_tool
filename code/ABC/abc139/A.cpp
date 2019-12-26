#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s, t;
    cin >> s >> t;
    int count = 0;
    for(int i=0; i<3; i++){
        if(s[i]==t[i]){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}