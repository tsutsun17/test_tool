#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    pair<int, int> max1, max2;
    max1 = make_pair(-1, 0), max2 = make_pair(-1, 0);
    for(int i=0; i<n; i++){
        int tmp = 0;
        cin >> tmp;
        a[i] = tmp;
        if(tmp >= max1.second){
            max2 = max1;
            max1.first = i;
            max1.second = tmp;
            continue;
        }

        if(tmp >= max2.second){
            max2.first = i;
            max2.second = tmp;
            continue;
        }
    }


    for(int i=0; i<n; i++){
        if(i==max1.first){
            cout << max2.second << endl;
            continue;
        }

        cout << max1.second << endl;
    }


    return 0;
}