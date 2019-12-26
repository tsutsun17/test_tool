#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double squ, ans=0;
    squ = w*h/2;
    if(w/2==x && h/2==y){
        ans = 1;
    }
    cout << squ << " " << ans <<endl;
    return 0;
}