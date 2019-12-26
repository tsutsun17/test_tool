#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector< pair<int, int> > a(n);

    for(int i=0; i<n; i++){
        int aa = 0;
        cin >> aa;
        a[i].first = aa;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        cout << a[i].second + 1 << ' ';
    }
    return 0;
}