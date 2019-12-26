#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> michi(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        michi[a]++; michi[b]++;
    }

    for(int i=0; i<n; i++){
        cout << michi[i] << endl;
    }
    return 0;
}