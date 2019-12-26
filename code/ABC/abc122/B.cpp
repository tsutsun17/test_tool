#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    vector<int> at(s.length()+1);
    at[0] = 0;
    for(int i=0; i<s.length(); i++){
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
            at[i+1] = at[i] + 1;
        }else{
            at[i+1] = 0;
        }
    }
    cout << *max_element(at.begin(), at.end()) << endl;
    return 0;
}