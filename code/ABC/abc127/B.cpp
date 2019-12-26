#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int r, d, x;
    cin >> r >> d >> x;
    for(int i=1; i<11; i++){
        int next = r*x-d;
        cout << next << endl;
        x = next;
    }
    return 0;
}