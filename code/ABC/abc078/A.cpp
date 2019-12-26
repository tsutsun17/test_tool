#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    char x, y;
    cin >> x >> y;
    map<char, int> s;
    s['A'] = 0;
    s['B'] = 1;
    s['C'] = 2;
    s['D'] = 3;
    s['E'] = 4;
    s['F'] = 5;
    if(x==y){
        cout << '=' << endl;
        return 0;
    }
    if(s[x] < s[y]){
        cout << '<' << endl;
    }else{
        cout << '>' << endl;
    }

    return 0;
}