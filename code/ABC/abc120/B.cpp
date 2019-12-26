#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int count=0;
    for(int i=100; i>=1; i--){
        if(a%i==0 && b%i==0){
            count++;
        }
        if(count == k){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}