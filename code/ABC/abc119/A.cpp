#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int year = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + s[3]-'0';
    int month = (s[5]-'0')*10 + (s[6]-'0');
    int day = (s[8]-'0')*10 + s[9]-'0';
    if(year<=2019){
        if(month<=4){
            cout << "Heisei" << endl;
            return 0;
        }
    }
    cout << "TBD" << endl;
    return 0;
}