#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    for(int i=111; i<=999; i += 111){
        if(n<=i){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}