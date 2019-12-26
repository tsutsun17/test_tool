#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    if(n%2==0){
        cout << setprecision(20) << (double)1/2 << endl;
    }else{
        double ans = 0;
        ans = (double)(n/2+1)/n;
        cout << setprecision(20) << ans << endl;
    }
    return 0;
}