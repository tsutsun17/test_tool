#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string today;
    cin >> today;
    if(today == "Sunny"){
        cout << "Cloudy" << endl;
        return 0;
    }

    if(today == "Cloudy"){
        cout << "Rainy" << endl;
        return 0;
    }

    cout << "Sunny" << endl;
    return 0;
}