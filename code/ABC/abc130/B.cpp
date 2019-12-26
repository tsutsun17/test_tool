#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    int sum;
    for(int i=0; i<n; i++){
        int j;
        cin >> j;
        sum += j;
        if(sum > x){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << n+1 << endl;
    return 0;
}