#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string n;
    cin >> n;
    if((n[0] == n[1] || n[2] == n[3]) && (n[1] == n[2])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}