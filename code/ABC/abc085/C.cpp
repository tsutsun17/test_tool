#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, y;
    cin >> n >> y;
    for(int i=0; i<n+1; i++){
        for(int j=0; i+j<n+1; j++){
            int sum = 10000*i + 5000*j + 1000*(n-i-j);
            if(sum == y){
                cout << i << ' ' << j << ' ' << n-i-j;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}