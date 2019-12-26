#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << W*(H-h) - w*(H-h) << endl;
    return 0;
}