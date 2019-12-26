#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, l;
    cin >> n >> l;
    int min_a, max_a, sum;
    min_a = l;
    max_a = l+n-1;
    sum = n*(2*l+(n-1))/2;
    if(min_a*max_a <= 0){
        cout << sum << endl;
    }else if(min_a > 0){
        cout << sum-min_a << endl;
    }else if(min_a < 0){
        cout << sum-max_a << endl;
    }
    return 0;
}