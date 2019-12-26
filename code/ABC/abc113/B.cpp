#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, t, a;
    cin >> n >> t >> a;

    vector<pair<double, int> > T(n);
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        T[i].first = abs(t-h*0.006-a);
        T[i].second = i;
    }

    sort(T.begin(), T.end());

    cout << T[0].second + 1 << endl;
    return 0;
}