#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    int tmp = 1;
    for(int i=0; i<n; i++){
        tmp = min(2*tmp, tmp+k);
    }

    cout << tmp << endl;
    return 0;
}