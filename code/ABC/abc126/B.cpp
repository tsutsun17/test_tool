#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    // TIPS: stringからintに変換
    int s_f = (s[0]-'0')*10 + (s[1]-'0');
    int s_s = (s[2]-'0')*10 + (s[3]-'0');

    if(s_f>0 && s_f<=12 && s_s>0 && s_s<=12){
        cout << "AMBIGUOUS" << endl;
        return 0;
    }
    if(s_s>0 && s_s<=12){
        cout << "YYMM" << endl;
        return 0;
    }
    if(s_f>0 && s_f<=12){
        cout << "MMYY" << endl;
        return 0;
    }
    cout << "NA" << endl;
    return 0;
}