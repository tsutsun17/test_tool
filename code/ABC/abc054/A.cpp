#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    if(a==b){
        cout << "Draw" << endl;
        return 0;
    }
    if(a<b){
        if(a!=1){
            cout << "Bob" << endl;
            return 0;
        }else{
            cout << "Alice" << endl;
            return 0;
        }
    }
    if(b<a){
        if(b!=1){
            cout << "Alice" << endl;
            return 0;
        }else{
            cout << "Bob" << endl;
            return 0;
        }
    }

    return 0;
}