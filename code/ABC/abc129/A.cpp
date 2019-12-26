#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> l(3);
    for(int i=0; i<3; i++){
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    cout << l[0] + l[1] << endl;
    return 0;
}