#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int max_h=0;
    int count=0;
    for(int i=0; i<n; i++){
        max_h = max(max_h, h[i]);
        if(max_h == h[i]){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}